#include "matrix/src/Application.h"
#include <string>

namespace MX {
    
    Application::Application() {
        MX_INFO("Creating Application");
    }

    Application::~Application() {

    }

    Application &Application::get() {
        static Application instance;
        return instance;
    }

    void Application::initialize(void (*initialize_func)()) {
        // set up window 
        m_Running = m_Window->createContext();
        
        // set up API
        m_Running = m_API->createContext();
        
        // set up GUI
        m_GUI->initialize();

        if (m_Running) {
            MX_SUCCESS("Application initialization");
        } else {
            MX_FATAL("Application initialization");
        }
    }

    void Application::update(void (*update_func)()) {
        m_Window->update();

        m_Window->controllerCallback();
         
        update_func();
    }

    void Application::render() {
        m_Window->update();

        m_API->clear();

        m_API->render();

        m_GUI->render();   

        m_Window->render();
    }

    void Application::clean() {
        m_GUI->clean();

        m_Window->close();
    }

    void Application::stop() {
        m_Running = false;
    }
}
