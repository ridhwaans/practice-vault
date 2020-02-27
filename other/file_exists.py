#!/usr/bin/env python
import os
import mock
import pytest
import __builtin__

def main(prompt):
  filename = raw_input(prompt) #ask for filename using the given prompt
  if validate(filename):
    print "File exists"
    return "File exists"
  else:
    print "File does not exist"
    return "File does not exist"

def validate(input):
    if input is None:
        return False
    input = input.strip()
    if input == '':
        return False
    elif not (os.path.exists(input)):
        return False
    else:
        return True

if __name__ == "__main__":
    main("Enter filename in current directory:")

# python -m pytest file_exists.py
# valid: ['print-file.py']
# invalid: [None, '', 'nonexistent']
def test_01():
    with mock.patch.object(__builtin__, 'raw_input', side_effect=['file_exists.py']):
        assert main("Enter filename") == "File exists"

def test_02():
    with mock.patch.object(__builtin__, 'raw_input', side_effect=['  ']):
        assert main("Enter filename") == "File does not exist"

def test_03():
    with mock.patch.object(__builtin__, 'raw_input', side_effect=[None]):
        assert main("Enter filename") == "File does not exist"

def test_04():
    with mock.patch.object(__builtin__, 'raw_input', side_effect=['nonexistent']):
        assert main("Enter filename") == "File does not exist"
