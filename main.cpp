#include "classes.hpp"
#include <fstream>

/* codigo, outras informações opcionais

pedido: ponteiros (como pointers) ou usar o código
do cliente

vector size_t para pedidos, devem poder comprar n compras

verificar se já foi cadastrado o cliente

criar arquivos txt

metodo update para atualizar os clientes

mostrar os relatorios metodo show */

int main () {

    vector<clientes> ListOfClientes;
    vector<itens> ListOfItens;
    vector<pedidos> ListOfPedidos;
    
    char ch;

    

    do {

        cout << "---------------------------------------" << endl;
        cout << "My Business System Manager" << endl;
        cout << "1. Register a client" << endl;
        cout << "2. Register a product" << endl;
        cout << "3. Make a order" << endl;
        cout << "4. Relatorio 1" << endl;
        cout << "5. Relatorio 2" << endl;
        cout << "6. Create a backup of your database" << endl;
        cout << "7. Exit program" << endl;
        cout << "--------------------------------------" << endl << endl;

        if(ch == '1') {
                
                //cadatro de clientes
                cout << "Enter a name of a new client: ";
                string nome;
                cin >> nome;
                cout << "Enter with a adress: ";
                string adress;
                cin >> adress;
                cout << "Enter with a CPF: ";
                string cpf;
                cin >> cpf;
                
                size_t id;
                // ID do cliente ser autoincrementado e ler o arquivo backup para não sobrescrever outro ID


                clientes newcliente(id, nome, adress, cpf);
                ListOfClientes.push_back(newcliente);
                printListOfClientes(ListOfClientes);
        }
            

        if(ch == '2') {
            //cadatro de itens
        }

        if(ch == '3') {
            //lançamentos de pedidos7
            printListOfItens(ListOfItens);
            cout << "Choose one: " << endl;
            getinline(id_item)
            
        }

        if(ch == '4') {
            //relatório 1
        }
        
        if(ch == '5') {
            //relatorio 2
        }

        if(ch == '6') {
            //criar arquivo (backup)
        }

    } while (ch != 7);
    

    return 0;
}

void printListOfItens(vector<itens> &List)
{

}

void printListOfClientes(vector<clientes> &List)
{
    for (size_t i = 0; i < List.size(); i++)
    {
        /* code */
    }
    
}