# [HLS][HLS]
**HLS** lists files and directories contained in an HFS volume ([Wikipedia][HFS+] **-** [Apple][Apple]).

## **flags**

This version of `ls command` ([man ls][LS]) works with the following flags:

| **Flag** | **Description** |
|----|--|
| -r | Sort entries in reverse order before displaying. |
| -1 |  each entry appears on a single line |
| -l | Display entries in long format. |
| -a | All files and directories are shown, including "invisible" files |
| -R | Like `-a` option, buth without `'.'` and `'..'` "invisible" files only. |

-f this is the default mode after execute the funtion `opendir()`
Do not sort directory contents; list them in the order they appear in the directory. This option effectively enables -a and -U and disables -l, -s, and -t.



[//]: # (links)
  [HLS]: <https://linux.die.net/man/1/hls>
  [HFS+]: <https://en.wikipedia.org/wiki/HFS_Plus>
  [Apple]: <https://developer.apple.com/library/archive/technotes/tn/tn1150.html>
  [LS]: <https://man7.org/linux/man-pages/man1/ls.1.html>