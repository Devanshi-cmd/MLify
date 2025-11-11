#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
    // 1. SETUP WINDOW
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "White Box", NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();

    // Setup 2D coordinates (0,0) to (800,600)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);


    // 2. CREATE FBO + TEXTURE
    GLuint fbo, texture;

    // Create FBO
    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);

    // Create texture (storage)
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 800, 600, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Attach texture to FBO
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

    // Clear FBO to black
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);


    // 3. DRAW WHITE BOX INTO FBO
    glColor3f(1, 1, 1);  // White
    glBegin(GL_QUADS);
        glVertex2f(300, 200);  // Top-left
        glVertex2f(500, 200);  // Top-right
        glVertex2f(500, 400);  // Bottom-right
        glVertex2f(300, 400);  // Bottom-left
    glEnd();

    // Done drawing to FBO
    glBindFramebuffer(GL_FRAMEBUFFER, 0);


    // 4. MAIN LOOP - DISPLAY FBO ON SCREEN
    while (!glfwWindowShouldClose(window))
    {
        // Clear window
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw FBO texture to screen (as fullscreen quad)
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
        glColor3f(1, 1, 1);

        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex2f(0, 0);
            glTexCoord2f(1, 0); glVertex2f(800, 0);
            glTexCoord2f(1, 1); glVertex2f(800, 600);
            glTexCoord2f(0, 1); glVertex2f(0, 600);
        glEnd();

        glDisable(GL_TEXTURE_2D);

        // Show on screen
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteTextures(1, &texture);
    glDeleteFramebuffers(1, &fbo);
    glfwTerminate();
    return 0;
}