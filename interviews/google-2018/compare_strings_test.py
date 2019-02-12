#!/usr/bin/env python

import compare_strings
import unittest

class compare_strings_test(unittest.TestCase):

    def test_01(self):
        raised = False
        try:
            compare_strings.compare('Toronto', 'Cleveland')
        except:
            raised = True
        self.assertFalse(raised, 'Exception raised')

    def test_02(self):
        equivalent = compare_strings.compare('Toronto', 'Cleveland')
        self.assertEquals(equivalent, False)

    def test_03(self):
        equivalent = compare_strings.compare('Toronto', 'Toroo\b\bnto')
        self.assertEquals(equivalent, False)

    def test_04(self):
        equivalent = compare_strings.compare('Toronto', 'Torooo\b\bntt\bo')
        self.assertEquals(equivalent, True)

if __name__ == "__main__":
    unittest.main()
