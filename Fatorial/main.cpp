#include <cwf/cppwebapplication.h>


int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
};


class FatorialController : public CWF::Controller
{

public:
    void doGet(CWF::Request &request, CWF::Response &response) const override
    {
        /*
        response.write("<html><body><form action=\"/fatorial\" method=\"POST\">"
                       "Fatorial de: <input type=\"text\" name=\"numero\"/>"
                       "<input type=\"submit\" value=\"Calcular\" <\form> "  );
        */

        request.getRequestDispatcher("/pages/fatorial.html").forward(request, response);
    }

    void doPost(CWF::Request &request, CWF::Response &response) const override
    {
        /*
        response.write("<html><body>"
                       "<h1> Resultado: " +
                       QByteArray::number( factorial( request.getParameter("numero").toInt() ))  + " </h1>" +
                       "</body></html>");
        */

        CWF::Variant numero(request.getParameter("numero"));
        CWF::Variant resultado(factorial( request.getParameter("numero").toInt()));
        request.addAttribute("numero", &numero);
        request.addAttribute("resultado", &resultado);
        request.getRequestDispatcher("/pages/fatorialresult.view").forward(request, response);
    }
};

int main(int argc, char* argv[])
{
    CWF::CppWebApplication server(argc, argv, "/home/andreibr/Workspaces/QTworkspace/aulacwf/Fatorial/server");
    server.addController<FatorialController>("/fatorial");
    server.start();
}
