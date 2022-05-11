#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


class Window    //Class Creating Window for drawing the figures OpenGL intro  him 
{


public:

    GLFWwindow* Creat(int WIDTH, int HEIGTH,const  char *title, GLFWmonitor* monitor , GLFWwindow* share) const
    {
              GLFWwindow* window =   glfwCreateWindow( WIDTH,  HEIGTH,  title ,  monitor =NULL,  share = NULL);
              return  window;
    };

    void ContexCurrent(GLFWwindow* w)
    {

        GLFWwindow* glfwMakeContextCurrent(w);
    };

    bool  isClose(GLFWwindow* window) const
    {
        
       if( glfwWindowShouldClose( window))
       {
           return true;
       }
       else
       {
           return false;
       }

    };
 private:
     GLFWwindow *window;
     const char* title;
     int value;
};

class VertexBuffer {



public:
    GLuint index;
    
    void Glad()  // init  glad
    {

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "not inicializad GLAD";
        }
        
    };
    void   Create(uint32_t n,GLuint* vbo)
    {
        
        glGenBuffers(n, vbo);
        
    };
      

    void Bind(GLenum target, GLuint vbo)
    {
         glBindBuffer( target, vbo);
    };


    void Data(GLenum target,GLsizeiptr size,const void* Vertex,GLenum usage)
    {
        glBufferData(target, size, Vertex, usage) ;
    }

    GLuint  isEnable(GLuint index)
    {
         glEnableVertexAttribArray( index);
         return  index;
    };

    void  Pointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer)
    {
    
        glVertexAttribPointer(index,size,type,normalized,stride,pointer);
    
    
    };
    void Draw(GLenum mode, GLint first, GLsizei count)
    {
        glDrawArrays(mode, first, count);

    };



private:

    int  size;
    
    
};



class Application
{
public:
    void Run()
    {
        // creating window and opengl initialization
        // mVAO.Create();
//        GLenum target = GL_ARRAY_BUFFER;
        glfwInit();
        
        GLuint vbo;
        VertexBuffer vertex;
        Window w;
        GLFWwindow* window = w.Creat(600, 800, "Hello", 0, 0);
        vertex.Create(1, &vbo);
        vertex.Bind(GL_ARRAY_BUFFER, vbo);
        float Vertex[6] = {
        -0.5f, -0.5f,
         0.0f, 0.5f,
         0.5f, -0.5f,
        };
        vertex.Data(GL_ARRAY_BUFFER, 6 * sizeof(float), Vertex, GL_STATIC_DRAW);
        vertex.isEnable(0);
        vertex.Pointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
        if (window == NULL)
        {
            std::cout << "Filed creat window";
            glfwTerminate();
        }



        w.ContexCurrent(window);

 //       vertex.Glad();
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {

            std::cout << "not inicializad GLAD";
            
        }

        while (!w.isClose(window))
        {
            vertex.Draw(GL_TRIANGLES, 0, 3);
            glfwSwapBuffers(window);
            glfwPollEvents();

        }
    }
private:
 //GLuint* vbo;
};


int main()
{
   // glfwInit();
   // gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    
    Application app;
    app.Run();
   
   

   
    

}





  






