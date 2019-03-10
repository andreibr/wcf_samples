#include <cwf/controller.h>
#include <cwf/cppwebapplication.h>

class HelloWorldController : public CWF::Controller
{
public:
    void doGet(CWF::Request &request, CWF::Response &response) const override
    {
        request.getRequestDispatcher("/pages/hello.html").forward(request, response);
    }

    void doPost(CWF::Request &request, CWF::Response &response) const override
    {
        CWF::Variant usuario(request.getParameter("nome"));
        request.addAttribute("usuario", &usuario);
        request.getRequestDispatcher("/pages/helloresults.view").forward(request, response);
    }
};


int main(int argc, char *argv[])
{
    CWF::CppWebApplication server(argc,
                                  argv,
                                  "/home/andreibr/Workspaces/QTworkspace/aulacwf/HelloWorld/server");

    server.addController<HelloWorldController>("/hello");

    return server.start();
}
