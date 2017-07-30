if not exist "../build" GOTO noFolder

rd /s /q "../build"
GOTO noFolder


: noFolder
mkdir "../build/Heretic3D/include/Heretic3D"
mkdir "../build/Heretic3D/bin"
mkdir "../build/Heretic3D/lib"
robocopy "SourceCode/" "../build/Heretic3D/include/Heretic3D" /s *.h
robocopy "../x64/Debug" "../build/Heretic3D/bin" /s *.*
robocopy "../x64/Debug" "../build/Heretic3D/lib" /s Heretic3D.lib
GOTO exit



: exit
exit 0