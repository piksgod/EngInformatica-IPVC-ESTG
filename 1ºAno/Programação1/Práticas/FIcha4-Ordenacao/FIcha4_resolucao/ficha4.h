#define MAX_EMPLOYEES 120
#define FILENAME "employees.dat"
#define TXT_FILENAME "colaboradores.txt"

typedef struct{
    unsigned short number;
    char name[100];
    unsigned long nif;
    float salary;

}Employee;

int saveEmployee(Employee e);

int listaInfo(Employee e);

void ordenaNome(Employee employees[], int nrEmployees);

void ordenaNIF(Employee employees[], int nrEmployees);

int salvarColaboradoresTXT();

void ordenaSalario(Employee employees[], int nrEmployees);

int existeNome(char *name);

