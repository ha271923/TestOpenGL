# TestOpenGL
A simple OpenGL to draw a triangle for study

# A. Study
[https://www.youtube.com/watch?v=1TVFHIQKCR0&list=PL0luF_aDUOooIB56NOFVTS4ahMzBHS_6z&index=1](https://youtu.be/1TVFHIQKCR0?list=PL0luF_aDUOooIB56NOFVTS4ahMzBHS_6z&t=135)

# B. Download
## Microsoft Visual Studio 2019
https://my.visualstudio.com/Downloads?q=visual%20studio%202019&wt.mc_id=o~msft~vscom~older-downloads
## GLEW
https://sourceforge.net/projects/glew/files/glew/2.1.0/glew-2.1.0-win32.zip/download
## GLFW
https://github.com/glfw/glfw/releases/download/3.4/glfw-3.4.bin.WIN32.zip

# C. Setup Visual Studio 2019
Solution Explorer\Project\Right Click\Properties  
### C++\General\Additional Include Directories
D:\Tools\OpenGL\glfw-3.4.bin.WIN32\include  
D:\Tools\OpenGL\glew-2.1.0\include  
### Linker\General\Additional Library Directories\
D:\Tools\OpenGL\glfw-3.4.bin.WIN32\lib-vc2019  
D:\Tools\OpenGL\glew-2.1.0\lib\Release\Win32  
### Linker\Input\Additional Dependencies\
opengl32.lib  
glfw3.lib  
glew32s.lib  
