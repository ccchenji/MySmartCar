::@echo off 

@for /d /r %%c in (KEA128_Debug,KEA128_Release,Debug,settings,Release) do @if exist %%c ( rd /s /q "%%c" & echo     É¾³ýÄ¿Â¼%%c) 

@for /r  %%c in (*.tmp,*.bak ,*.dep,*.sfr,Backup*,*.tmp.c ) do del "%%c"

pause