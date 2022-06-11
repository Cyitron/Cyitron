#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Clientes {
    private:
        size_t m_id_cliente;
        string m_name;
        string m_adress;
        string m_cpf;

    public:
        Clientes(size_t id, string name, string adress, string cpf)  {
            m_id_cliente = id;
            m_name = name;
            m_adress = adress;
            m_cpf = cpf;
        };

        void SetId_client(size_t id) {
            m_id_cliente = id;
        }
        void SetName(string name) {
            m_name = name;
        }
        void SetAdress(string adress) {
            m_adress = adress;
        }
        void SetCpf (string cpf) {
            m_cpf = cpf;
        }

        size_t GetId_client() {
            return m_id_cliente;
        }
        string GetName() {
            return m_name;
        }
        string GetAdress() {
            return m_adress;
        }
        string GetCpf() {
            return m_cpf;
        }
};

class Itens {
    private:
        size_t m_id_item;
        string m_description;
        float m_value;

    public:
        Itens(size_t id, string description, float value) {
            m_id_item = id;
            m_description = description;
            m_value = value;
        }

        void SetId_item(size_t id) {
            m_id_item = id;
        }
        void Setdesc(string description) {
            m_description = description;
        }
        void SetValor(float value) {
            m_value = value;
        }

        size_t GetId_item() {
            return m_id_item;
        }
        string GetDescription() {
            return m_description;
        }
        float GetValue() {
            return m_value;
        }
};

void LoadDataClients (vector<Clientes> &List);
void LoadDataItens (vector<Itens> &List);
bool SaveFile(string filename, const vector<pair<string, vector<string>>> &List);
bool SearchSubstr(string str, vector<Itens> &List);

int main () {

    char ch;

    vector<Clientes> ListOfClientes;
    vector<Itens> ListOfItens;
    //vector<Pedidos> ListOfPedidos;
    vector<pair<string, vector<string>>> ListOfFiles;
    
    //Load database
    LoadDataClients (ListOfClientes);
    LoadDataItens (ListOfItens);

    while (true) {
        cout << "---------------------------------------" << endl;
        cout << "My Business System Manager" << endl;
        cout << "1. Register a client" << endl;
        cout << "2. Show clients" << endl;
        cout << "3. Register a product" << endl;
        cout << "4. Show products" << endl;
        cout << "5. Make a order" << endl;
        cout << "6. Search for a substring of a item" << endl;
        cout << "7. Relatorio 2" << endl;
        cout << "8. Create a backup of your database" << endl;
        cout << "9. Exit program" << endl;
        cout << "--------------------------------------" << endl << endl;

        cout << "Enter with a number: ";
        cin >> ch;

        if(ch == '1') {
            //Cadatro de clientes

            cin.get(); //Problema com o buffer

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

            Clientes cliente(id_cliente, nome, adress, cpf);

            ListOfClientes.push_back(cliente);

            continue;
        }

        if(ch == '2') {
            for (size_t i = 0; i < ListOfClientes.size(); i++)
            {
                cout << "Id : " << ListOfClientes.at(i).GetId_client() << endl
                << "Name : " << ListOfClientes.at(i).GetName() << endl
                << "Adress : " << ListOfClientes.at(i).GetAdress() << endl
                << "CPF : " << ListOfClientes.at(i).GetCpf() << endl;
            }

            continue;
        } 

        if(ch == '3') {
            //Cadatro de itens

            size_t id_item = ListOfItens.size();

            cin.get();

            cout << "Enter with a drescription: ";
            string item_description;
            getline (cin, item_description);

            cout << "Enter with a value: ";
            float item_value;
            cin >> item_value;

            Itens item(id_item, item_description, item_value);

            ListOfItens.push_back(item);

            continue;
        }

        if(ch == '4') {
            for (size_t i = 0; i < ListOfItens.size(); i++)
            {
                cout << "Id of the item: " << ListOfItens.at(i).GetId_item() << endl
                << "Description : " << ListOfItens.at(i).GetDescription() << endl
                << "Value : " << ListOfItens.at(i).GetValue() << endl;
            }

            continue;
        }
        
        if(ch == '5') {
            //Lançamentos de pedidos
            /*
            size_t id_pedido = ListOfPedidos.size();
            size_t id_item;
            size_t id_client;

            cout << "Enter the code of the client : " << endl;
            cin >> id_client;

            cout << "Enter the code of the item : " << endl;
            cin >> id_item;
            */
            //pedidos pedido(id_pedido, id_client, id_item);

            //ListOfPedidos.push_back(pedido);
            //relatorio 2

            continue;
        }

        if(ch == '6') {

            size_t id_item = ListOfItens.size();
            string item_description;
            float item_value;

            Itens item(id_item, item_description, item_value);

            ListOfItens.push_back(item);
            
            cin.get();

            cout << endl << "Enter with a substring to search : " << endl;
            string str;
            getline(cin, str);

            if (SearchSubstr(str, ListOfItens) == true) {
                cout << "Number of strings found : " << id_item << endl << endl;
                for (size_t i = 0; i < ListOfItens.size(); i++)
                {
                    cout << item_description.at(i) << endl;
                }
            } else {
                cout << "Substring not found" << endl;
            }

            // size_t id_item = ListOfItens.size();

            // cin.get();

            // cout << "Enter with a drescription: ";
            // string item_description;
            // getline (cin, item_description);

            // cout << "Enter with a value: ";
            // float item_value;
            // cin >> item_value;

            // Itens item(id_item, item_description, item_value);

            // ListOfItens.push_back(item);

            continue;
        }

        if(ch == '7') {
            
            continue;
        }

        if(ch == '8') {
            
            continue;
        }

        if(ch == '9') {

            break;
        }
    }
    

    return 0;
}

void LoadDataClients (vector<Clientes> &List) {
    ifstream clients_file;
    clients_file.open("clientes.txt");

    string string_from_file;
    vector <string> list_from_file;

    if (!clients_file.is_open()) {
        cout << "File clientes.txt could not have been open!" << endl;
    } 
    else {
        cout << "File clientes.txt opened!" << endl;
    }

    while(getline(clients_file, string_from_file)) {
        list_from_file.push_back(string_from_file);
    }

    clients_file.close();

    size_t a = 0;

    for (size_t i = 0; i < list_from_file.size(); i += 4)
    {
        Clientes b (a, list_from_file.at(i+1), list_from_file.at(i+2), list_from_file.at(i+3));
        List.push_back(b);

        a++;
    }
}

void LoadDataItens (vector<Itens> &List) {

    ifstream itens_file;
    itens_file.open("itens.txt");

    string string_from_file;
    vector <string> list_from_file;

    if (!itens_file.is_open()) {
        cout << "File itens.txt could not have been open!" << endl;
    } 
    else {
        cout << "File itens.txt opened!" << endl;
    }

    while(getline(itens_file, string_from_file)) {
        list_from_file.push_back(string_from_file);
    }

    itens_file.close();
    
    size_t b = 0;

    for (size_t i = 0; i < list_from_file.size(); i += 3)
    {
        float a = stod (list_from_file.at(i+2));

        Itens c (b, list_from_file.at(i+1), a);
        List.push_back(c);

        b++;
    }
}

bool SearchSubstr(string str, vector<Itens> &List)
{
    ifstream itens_file;
    itens_file.open("itens.txt");

    string string_from_file;
    vector <string> list_from_file;

    if (!itens_file.is_open()) {
        cout << "File itens.txt could not have been open!" << endl;
    } 
    else {
        cout << "File itens.txt opened!" << endl;
    }

    while(getline(itens_file, string_from_file)) {
        list_from_file.push_back(string_from_file);
    }

    size_t b = 0;

    for (size_t i = 0; i < list_from_file.size(); i += 3)
    {
        float a = stod (list_from_file.at(i+2));

        Itens c (b, list_from_file.at(i+1), a);
        List.push_back(c);

        b++;
    }

    for (size_t i = 0; i < list_from_file.size(); i++) {

        string word = list_from_file.at(i);
        size_t pos = word.find(str);
        // for (size_t j = 0; j < List.at(i).second.size(); j++) {
        //     string word = List.at(i).second.at(j);
        //     size_t pos = word.find(str);
        //     if (pos < word.length()) {
        //         indices.push_back(j);
        //     }
        // }
    }

    itens_file.close();

    return true;
}

bool SaveFile(string filename, const vector<pair<string, vector<string>>> &List)
{
  ofstream fileWriter(filename);
  if (!fileWriter.is_open()) {
    cout << "Error, cannot open file" << endl;
    return false;
  }
  for (size_t i = 0; i < List.size(); i++) {
    for (size_t j = 0; j < List.at(i).second.size(); j++) {
      fileWriter << List.at(i).second.at(j) << endl;
    }
    fileWriter << "==================" << endl;
  }
  fileWriter.close();
  return true;
}