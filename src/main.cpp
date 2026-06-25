#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main()
{
    if (!glfwInit())
    {
        std::cout << "Error inicializando GLFW\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window =
        glfwCreateWindow(
            1280,
            720,
            "Buckit Engine",
            nullptr,
            nullptr);

    if (!window)
    {
        std::cout << "Error creando ventana\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader(
            (GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Error cargando GLAD\n";
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, 1280, 720);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(
            0.1f,
            0.1f,
            0.2f,
            1.0f);

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}