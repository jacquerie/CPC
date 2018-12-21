# -*- coding: utf-8 -*-

from __future__ import absolute_import, division, print_function


def Settings(**kwargs):
    return {
        'flags': [
            'std=c++14',
            '-Wall',
            '-Wextra',
            '-Werror',
            '-Wno-sign-compare',
        ],
    }
