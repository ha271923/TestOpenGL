#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

const char* vertexShaderSrc =
"#version 330 core                                         \n "
"layout(location = 0) in vec3 aPos;                        \n "
"void main() {                                             \n "
"        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);} \n ";

const char* fragmentShaderSrc =
"#version 330 core                                         \n "
"out vec4 FragColor;                                       \n "
"void main()                                               \n "
"        FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);}        \n ";

float vertices[] = { // OpenGL's draw point sequence is clockwise
    -0.5f, -0.5f, 0.0f, // idx=1
     0.5f, -0.5f, 0.0f, // idx=2
     0.0f,  0.5f, 0.0f, // idx=3

     // 0.5f, -0.5f, 0.0f, // same with idx2
     // 0.0f,  0.5f, 0.0f, // same with idx3
     0.8f, 0.8f, 0.0f   // idx=0
};

unsigned int indices[] = { // idx array for EBO
    0,1,2,
    2,1,3
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void createATriangle();
void drawATriangle();

int main()
{
    printf("OpenGL ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // use OpenGL 3.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // create Window
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Init GLEW
    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        printf("Init GLEW ok");
    }

    // setup viewport
    glViewport(0, 0, 800, 600);

#if ENABLE_CULL_FACE
    // for do not draw front/back side of triangle
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    // glCullFace(GL_FRONT);
#endif

#if true
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#endif

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    createATriangle();

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        // fill color
        glClearColor(0.0f, 1.0f, 1.0f, 1.0f); // RGBA
        glClear(GL_COLOR_BUFFER_BIT);

        // draw a triangle
        drawATriangle();

        // typical
        glfwSwapBuffers(window); // OpenGL uses double buffer for fix flickering issue
        glfwPollEvents();
    }

    // end
    printf("OpenGL --------------------------------------------------------------------------\n");
    char ch = getchar();
    glfwTerminate(); // end OpenGL
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    printf("framebuffer_size_callback w=%d   h=%d\n", width, height);
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        printf("A");
    else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
        printf("B");
}

unsigned int VAO;
unsigned int shaderProgram;
void createATriangle() {
    // GPU: VBO
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // GPU: VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // GPU: EBO
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // GPU: vertex shader
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSrc, NULL);
    glCompileShader(vertexShader);

    // GPU: fragment shader
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSrc, NULL);
    glCompileShader(fragmentShader);

    // GPU: create program by shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void drawATriangle() {
    glBindVertexArray(VAO);
    glUseProgram(shaderProgram);

    // glDrawArrays(GL_TRIANGLES, 0, 6); // use VAO
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); // use EBO
}