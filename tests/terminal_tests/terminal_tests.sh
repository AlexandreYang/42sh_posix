#!/bin/sh

C_CYAN="\033[36;1m"
C_GREEN="\033[32;1m"
C_RED="\033[31;1m"
C_CLEAR="\033[0m"

RENDU_PATH="`pwd`"
TESTS_ROOT="$RENDU_PATH/tests/terminal_tests/"

exit_status=0

make

if [ "$?" -ne "0" ]; then
    exit 1
fi

print_result ()
{
    if [ $1 -eq 0 ]
    then
        /usr/bin/printf $C_GREEN"$2"$C_CLEAR"\c"
    else
        /usr/bin/printf $C_RED"$2"$C_CLEAR"\c"
        exit_status=1
    fi
    /usr/bin/printf " \c"
}

diff_test ()
{
    testsuite=$1
    testcase=$2
    testcase_path="$TESTS_ROOT/$testsuite/$testcase"
    testcase_tmp="$testcase_path/.tmp"
    testcase_tmp_stdout="$testcase_tmp/actual_stdout"
    testcase_tmp_stderr="$testcase_tmp/actual_stderr"
    testcase_tmp_bash_stdout="$testcase_tmp/expected_stdout"
    testcase_tmp_bash_stderr="$testcase_tmp/expected_stderr"

    if ! [ -z ${CI+x} ] && test "${testcase#*_noci_spec}" != "$testcase"; then
        echo "skip no ci    ./42sh tests/terminal_tests/$testsuite/$testcase/input.sh"
        return
    fi
    mkdir -p $testcase_tmp
    rm -f $testcase_tmp/*
    export TEST_SHELL TEST_STDOUT TESTS_ROOT
    TEST_SHELL=$RENDU_PATH/42sh
    TEST_STDOUT=$testcase_tmp_stdout
    : > $TEST_STDOUT
    bash $testcase_path/input.sh
    if [ ! -f $testcase_path/expected_stdout ] || [ ! -f $testcase_path/expected_stderr ]; then
        TEST_SHELL='bash --posix'
        TEST_STDOUT=$testcase_tmp_bash_stdout
        : > $TEST_STDOUT
        sleep 0.1
        bash $testcase_path/input.sh
    fi
    if [ -f $testcase_path/expected_stdout ]; then
        expected_stdout_file=$testcase_path/expected_stdout
    else
        expected_stdout_file=$testcase_tmp_bash_stdout
    fi
    sleep 0.1
    # if [ -f $testcase_path/expected_stderr ]; then
    #     expected_stderr_file=$testcase_path/expected_stderr
    # else
    #     expected_stderr_file=$testcase_tmp_bash_stderr
    # fi
    diff $expected_stdout_file $testcase_tmp_stdout
    stdout_res="$?"
    # diff $expected_stderr_file $testcase_tmp_stderr
    # stdout_err="$?"
    if [ ! -s $testcase_tmp_stdout ]
    then
        stdout_res="1"
    fi
    print_result "$stdout_res" stdout
    # print_result "$stdout_err" stderr
    echo "./42sh tests/terminal_tests/$testsuite/$testcase/input.sh"
}

/usr/bin/printf $C_CYAN"====== START AST DIFF TESTS ======"$C_CLEAR"\n"

for CASE_PATH in $TESTS_ROOT/${PATTERN:-*}; do
    if [ -d "${CASE_PATH}" ]; then
        for TEST_PATH in $CASE_PATH/${PATTERN_SPEC:-*_spec}; do
            if [ -d "${TEST_PATH}" ]; then
                diff_test `basename $CASE_PATH` `basename $TEST_PATH`
            fi
        done
    fi
done

/usr/bin/printf $C_CYAN"======  END TESTS  ======"$C_CLEAR"\n"

exit $exit_status
