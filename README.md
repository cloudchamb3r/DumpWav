# DumpWav 
Dump your sound as WAV on Windows!

## PREREQUISITE 

**Target dll** => AudioSes.dll (version 10.0.19041.2364, Windows 10, x86_64)


## -  How Can I Check My AudioSes.dll Version?
Open powershell and type `$(gcm audioSes.dll).Version`. 

``` powershell
> $(gcm audioSes.dll).Version

Major  Minor  Build  Revision
-----  -----  -----  --------
10     0      19041  2364
```
The compatible version is 10.0.19041.2364. In other cases, I can't be sure that this will work well.