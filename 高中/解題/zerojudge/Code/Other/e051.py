# -*- coding: utf-8 -*-
"""
Created on Mon Sep 28 19:31:44 2020

@author: User
"""

s = str( input("") )
p = len(s)
print (s[0] , end="")
for i in range (p-2):
    print ( "_" , end="")
print (s[p-1])