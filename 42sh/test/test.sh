#!/bin/bash

check_test()
{
  if [ "$3" = "$4" ]; then
    if [ "$5" = "$6" ]; then
      echo "Test $1: $2 -> Passed !"
      return 1
    else
      echo "Test $1: $2 -> Invalid exit status !"
      return 0
    fi
  else
    echo "Test $1: $2 -> Failed !"
    return 0
  fi
}

launch_test()
{
  if [ "$1" = "new_test" ]; then
    TEST=0
    return 0
  fi
  TEST=$((TEST+1))
  NB_TEST=$((NB_TEST+1))
  NAME="$1"
  MYSH=$(echo "$2" | "$BINARY" 2>/dev/null)
  RET1=$(echo $?)
  TCSH=$(echo "$2" | /bin/tcsh 2>/dev/null)
  RET2=$(echo $?)
  if [ "$3" = "no_return" ]; then
    RET1=$RET2
  fi
  check_test $TEST "$NAME" "$MYSH" "$TCSH" "$RET1" "$RET2"
  return_status=$((return_status + $?))
  return $return_status
}

new_test()
{
  INIT="new_test"
  ARGS=$INIT
  launch_test "$INIT" "$ARGS"
}

BINARY=$1
if ! type "$BINARY" &>/dev/null; then
  exit 1
fi
echo -e "What is the correct name of the boss ?
[1]Nollan - [2]Nolann - [3]Nollann - [4]Nolane : \c"
read response
if [ "$response" = "2" ]; then
  echo "Well done !"
else
  echo "Bad response ! Try again !"
  exit 1
fi

echo "
        :::     ::::::::   ::::::::  :::    :::
      :+:     :+:    :+: :+:    :+: :+:    :+:
    +:+ +:+        +:+  +:+        +:+    +:+
  +#+  +:+      +#+    +#++:++#++ +#++:++#++
+#+#+#+#+#+  +#+             +#+ +#+    +#+
     #+#   #+#       #+#    #+# #+#    #+#
    ###  ##########  ########  ###    ###

            Feat Nolann the boss !
And his partners : Ahmed / Yannick / Enzo / Lucien
"

echo -e "\nMiniShell1:"
new_test
launch_test "empty" ""
launch_test "simple exec" "         ls       -l         -a"
launch_test "simple cd" "cd ../"
launch_test "advanced cd" "cd ../../../../../.."
launch_test "cd -" "cd ..; cd -"
launch_test "simple setenv" "setenv test test"
launch_test "setenv error" "setenv a1* a2* a3*"
launch_test "unsetenv (empty)" "unsetenv"
launch_test "simple unsetenv" "unsetenv test"
launch_test "wrong simple command" "exitt"

echo -e "\nMiniShell2:"
new_test
launch_test "separator basic" "ls ; pwd"
launch_test "multiple separator" "pwd ; cd .. ; pwd; whoami"
launch_test "complex separator" "ls -l ; pwd; wc -l;whoami         ; date"
launch_test "pipe with multi-exec" "ls | pwd | whoami | ls -l | ls -la | wc -l" "no_return"
launch_test "pipe with builtins" "ls | cd .. | pwd | cd - | ls -la" "no_return"
launch_test "pipe with big input" "ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls" "no_return"
launch_test "echo with sleep" "echo cat /etc/resolv.conf; sleep 0.5; echo ls -l /etc;echo pwd"
launch_test "echo with simple quotes" "echo 'cat /etc/resolv.conf'; sleep 0.5; echo 'ls -l /etc';echo 'pwd'"
launch_test "multi exec 1" "cat /etc/shells | head -c 5 | wc -c"
launch_test "multi exec 2" "cat /etc/resolv.conf | grep nameserver | cat -e"

echo -e "\nOperators:"
new_test
launch_test "simple && operator" "pwd && cat test.sh"
launch_test "advanced && operator" "ls && pwd && whoami && cat -e /etc/passwd"
launch_test "simple || operator" "pwd || cat test.sh"
launch_test "advanced || operator" "ls || pwd || whoami || cat -e /etc/passwd"

echo -e "\nRedirections:"
new_test
launch_test "output redirect" "ls -la > file"
launch_test "output double-redirect" "head /etc/resolv.conf >> file"
launch_test "input redirect" "cat < file"
rm -f file

echo -e "\nVariables:"
new_test
launch_test "basic set" "set"
launch_test "simple variable" "set x=2 ; set"
launch_test "multi variables" "set x=test ; set y=4000 ; set z=-20 ; set"

echo -e "\nBuiltins:"
new_test
launch_test "foreach" "foreach n ( 1 2 3 4 5 )
ls -la
whoami
pwd
end"
launch_test "repeat" "repeat 10 pwd"
launch_test "where" "setenv PATH /usr/bin ; where tcsh"
launch_test "which" "which setenv"
launch_test "exit" "exit 71"

echo -e "\nJobs:"
new_test
launch_test "simple job" "ls &"
launch_test "check jobs" "jobs"
launch_test "foreground" "fg"
launch_test "background" "bg"

echo -e "\nAlias:"
new_test
launch_test "simple alias 1" "alias ll ls -la
              ll"
launch_test "simple alias 2" "alias mydate date
              mydate"
launch_test "alias with arguments" "alias list ls
              list /home"
launch_test "multi separators" "alias showstuff 'date ; cal ; echo Files: ; ls'
              showstuff"
launch_test "protecting pipe" "alias lnd 'ls -l | grep -v ^d'
              lnd"

echo -e "\nBacktick:"
new_test
launch_test "simple exec 1" 'ls `echo -l`'
launch_test "simple exec 2" 'ls `ls -l | grep s` | cat -e'

echo -e "\n#### SCORE ####"
echo "Tests number: $NB_TEST"
echo "Tests passed: $return_status"
echo "Tests failed: $((NB_TEST - return_status))"
echo "Total: $(((return_status * 100) / NB_TEST))%"