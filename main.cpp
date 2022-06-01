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

    do {
        if(ch == '1') {
            //Cadatro de clientes

            size_t id_cliente = ListOfClientes.size();
            cout << "Enter a name of a new client: ";
            string nome;
            getline (cin, nome);

            cout << "Enter with a adress: ";
            string adress;
            getline (cin, adress);

            cout << "Enter with a CPF: ";
            string cpf;
            getline (cin, cpf);

            clientes cliente(id_cliente, nome, adress, cpf);

            ListOfClientes.push_back(cliente);
        }
            

        if(ch == '2') {
            //Cadatro de itens

            size_t id_item = ListOfItens.size();

            cout << "Enter with a adress: ";
            string item_description;
            getline (cin, item_description);

            cout << "Enter with a value: ";
            float item_value;
            cin >> item_value;

            itens item(id_item, item_description, item_value);

            ListOfItens.push_back(item);
        }

        if(ch == '3') {
            //Lançamentos de pedidos

            size_t id_pedido = ListOfPedidos.size();
            size_t id_item;
            size_t id_client;

            cout << "Enter the code of the client : " << endl;
            cin >> id_client;

            cout << "Enter the code of the item : " << endl;
            cin >> id_item;

            //pedidos pedido(id_pedido, id_client, id_item);

            //ListOfPedidos.push_back(pedido);
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