# uncompyle6 version 3.9.0
# Python bytecode version base 3.4 (3310)
# Decompiled from: Python 3.4.3 (default, Nov 12 2018, 22:25:49) 
# [GCC 4.8.4]
# Embedded file name: 100-password
# Compiled at: 2023-08-19 00:29:19
pass
# okay decompiling 100-password
# uncompyle6 version 3.9.0
# Python bytecode version base 3.4 (3310)
# Decompiled from: Python 3.4.3 (default, Nov 12 2018, 22:25:49) 
# [GCC 4.8.4]
# Embedded file name: 100-crackme.py
# Compiled at: 2017-01-06 00:44:37
# Size of source mod 2**32: 195 bytes
pwd = input('Password: ')
ok = 'Zen of Python'
ok = ok + ' C'
ok = ok[1:3] + ok[3] + ok[14] + ok[3] + ok[7:9] + ok[:6][::-1]
if pwd == ok:
    print('OK')
else:
    print('KO')
# okay decompiling .pyc
# decompiled 2 files: 2 okay, 0 failed
