#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Clients {
    private:
        size_t m_id_client;
        string m_name;
        string m_cpf;
        string m_adress;
        string m_number;
        

    public:
        Clients(size_t id, string name, string cpf, string adress, string number)  {
            m_id_client = id;
            m_name = name;
            m_cpf = cpf;
            m_adress = adress;
            m_number = number;
        }

        void SetId_client(size_t id) {
            m_id_client = id;
        }
        void SetName(string name) {
            m_name = name;
        }
        void SetCpf (string cpf) {
            m_cpf = cpf;
        }
        void SetAdress(string adress) {
            m_adress = adress;
        }
        void SetNumber(string number) {
            m_number = number;
        }
        

        size_t GetId_client() {
            return m_id_client;
        }
        string GetName() {
            return m_name;
        }
        string GetCpf() {
            return m_cpf;
        }
        string GetAdress() {
            return m_adress;
        }
        string GetNumber() {
            return m_number;
        } 
};

class Products {
    private:
        size_t m_id_product;
        string m_description;
        float m_value;
        int m_quantity;

    public:
        Products(size_t id, string description, float value) {
            m_id_product = id;
            m_description = description;
            m_value = value;
            m_quantity = 0;
        }

        void SetId_Product(size_t id) {
            m_id_product = id;
        }
        void SetDescription(string description) {
            m_description = description;
        }
        void SetValue(float value) {
            m_value = value;
        }
        void SetQuantity(int quantity) {
            m_quantity = quantity;
        }

        size_t GetId_Product() {
            return m_id_product;
        }
        string GetDescription() {
            return m_description;
        }
        float GetValue() {
            return m_value;
        }
        int GetQuantity() {
            return m_quantity;
        }
};

class Orders {
    private:
        size_t  m_id_order;
        size_t m_id_client;
        vector<pair<size_t, int>> m_id_product;

    public:
        Orders(size_t  id_order, size_t id_client, vector<pair<size_t, int>> id_product) {
            m_id_order = id_order;
            m_id_client = id_client;
            m_id_product = id_product;
        }

        void SetOrder(size_t id_order) {
            m_id_order = id_order;
        }
        void SetOrdClient(size_t id_client) {
            m_id_client = id_client;
        }
        void SetOrdProducts(vector<pair<size_t, int>> id_products) {
            m_id_product = id_products;
        }

        size_t GetId_Orders() {
            return m_id_order;
        }
        size_t GetId_Client() {
            return m_id_client;
        }
        vector<pair<size_t, int>> GetId_Products() {
            return m_id_product;
        }

        
};

///////////////////////////////////////////////////////////////////////////////////

void load_dataclients (vector<Clients> &List);
void load_dataproducts (vector<Products> &List);
void update_clients(vector <Clients> &List1, vector<Orders> &List2);
void update_products(vector <Products> &List1, vector<Orders> &List2);
void load_dataorders (vector<Orders> &List1, vector<Products> &List2);
size_t stringToSize_t (string str);
void save_dataclients (vector<Clients> &List);
void save_dataproducts (vector<Products> &List);
void save_dataorders (vector<Orders> &List);


int main () {
    char choice;

    vector<Clients> ListOfClients;
    vector<Products> ListOfProducts;
    vector<Orders> ListOfOrders;
    
    //Load database
    load_dataclients (ListOfClients);
    load_dataproducts (ListOfProducts);
    load_dataorders (ListOfOrders, ListOfProducts);

    while (true) {
        cout << "---------------------------------------" << endl;
        cout << "My Business System Manager" << endl;
        cout << "1. Register a client" << endl;
        cout << "2. Register a product" << endl;
        cout << "3. Update clients data" << endl;
        cout << "4. Update products data" << endl;
        cout << "5. Register an order" << endl;
        cout << "6. Show clients and products" << endl;
        cout << "7. Show orders" << endl;
        cout << "8. Search a product by substring" << endl;
        cout << "9. Most ordered products" << endl;
        cout << "a. Orders per clients" << endl;
        cout << "0. Exit program" << endl;
        cout << "--------------------------------------" << endl;

        cin >> choice;

        if(choice == '1') {
            //Cadatro de clientes

            cin.get();

            size_t id_client = ListOfClients.size();

            cout << "Enter the name of the new client : ";
            string name;
            getline (cin, name);

            cout << "Enter the CPF : ";
            string cpf;
            getline (cin, cpf);

            cout << "Enter the adress : ";
            string adress;
            getline (cin, adress);

            cout << "Enter the number : ";
            string number;
            getline (cin, number);

            Clients new_client(id_client, name, cpf, adress, number);

            ListOfClients.push_back(new_client);
        }

        if(choice == '2') {
            //Cadatro de products

            size_t product_item = ListOfProducts.size();

            cin.get();

            cout << "Enter a description: ";
            string product_description;
            getline (cin, product_description);

            cout << "Enter a value: ";
            float product_value;
            cin >> product_value;

            Products new_product(product_item, product_description, product_value);

            ListOfProducts.push_back(new_product);
        }

        if(choice =='3') {
            //Atualizar dados
            update_clients(ListOfClients, ListOfOrders);
        }

        if(choice == '4') {
            //Atualizar dados
            update_products(ListOfProducts, ListOfOrders);
        }

        if(choice == '5') {
            //Criar um pedido

            char choice2;
            size_t id_order = ListOfOrders.size();
            size_t id_client, id_product;
            int quant_product;
            vector<pair<size_t, int>> id_products;

            cout << "Enter the ID of the client who placed the order : ";
            cin >> id_client;

            do {
                pair<size_t, int> new_pair;

                cout << "Enter the ID of the product : ";
                cin >> id_product;

                cout << "How much was orded : ";
                cin >> quant_product;

                new_pair.first = id_product;
                new_pair.second = quant_product;

                ListOfProducts.at(new_pair.first).SetQuantity(ListOfProducts.at(new_pair.first).GetQuantity() + new_pair.second);

                id_products.push_back(new_pair);

                cout << "Wanna add more? Y or N : ";
                cin >> choice2;
            } while(choice2 == 'y' || choice2 == 'Y');

            Orders new_order {id_order, id_client, id_products};
            ListOfOrders.push_back(new_order);
        }

        if(choice == '6') {
            cout << "List of clients : " << endl;
            for (size_t i = 0; i < ListOfClients.size(); i++)
            {
                cout << "Id of client: " << ListOfClients.at(i).GetId_client() << endl
                << "Name : " << ListOfClients.at(i).GetName() << endl
                << "CPF : " << ListOfClients.at(i).GetCpf() << endl
                << "Adress : " << ListOfClients.at(i).GetAdress() << endl
                << "Number : " << ListOfClients.at(i).GetNumber()<< endl << endl;
            }

            cout << "List of products : " << endl;
            for (size_t i = 0; i < ListOfProducts.size(); i++)
            {
                cout << "Id of the product : " << ListOfProducts.at(i).GetId_Product() << endl
                << "Description : " << ListOfProducts.at(i).GetDescription() << endl
                << "Value : " << ListOfProducts.at(i).GetValue() << endl << endl;
            }  
        }

        if(choice == '7') {
            float total = 0;
            cout << "List of orders" << endl;

            for (size_t i = 0; i < ListOfOrders.size(); i++)
            {
                cout << "Id : " << ListOfOrders.at(i).GetId_Orders() << endl
                << "Client : " << ListOfOrders.at(i).GetId_Client() << " - " << ListOfClients.at(ListOfOrders.at(i).GetId_Client()).GetName() << endl;

                for (size_t j = 0; j < ListOfOrders.at(i).GetId_Products().size(); j++)
                {
                    cout << "Product : " << ListOfOrders.at(i).GetId_Products().at(j).first << " - " << ListOfProducts.at(ListOfOrders.at(i).GetId_Products().at(j).first).GetDescription() << endl
                    << "Who much was orded : " << ListOfOrders.at(i).GetId_Products().at(j).second << endl;

                    total += ListOfProducts.at(ListOfOrders.at(i).GetId_Products().at(j).first).GetValue() * (float)ListOfOrders.at(i).GetId_Products().at(j).second;
                }
                cout << "Total : " << total << endl;
                total = 0;
            }
        }
        
        if(choice == '8') {
            string substring;

            cout << "Enter a substring to search:";
            cin >> substring;

            for (size_t i = 0; i < ListOfProducts.size(); i++) {
                if (ListOfProducts.at(i).GetDescription().find(substring) <= ListOfProducts.at(i).GetDescription().length()) {
                    cout << ListOfProducts.at(i).GetId_Product() << " has the product :" << ListOfProducts.at(i).GetDescription() << endl;
                }
            }
        }

        if(choice == '9') {
            vector<pair<size_t, int>> quantities;

            for (size_t i = 0; i < ListOfProducts.size(); i++) {   
                pair<size_t, int> new_quantity (i, ListOfProducts.at(i).GetQuantity());
                quantities.push_back(new_quantity);
            }
            
            for (size_t i = 0; i < quantities.size(); i++) {
                for (size_t j = i+1; j < quantities.size(); j++) {
                    if(quantities.at(j).second > quantities.at(i).second) {
                        swap(quantities.at(i), quantities.at(j));
                    }
                } 
            }

            for (size_t i = 0; i < quantities.size(); i++) {
                cout << "Products : " << quantities.at(i).first << " - " << ListOfProducts.at(quantities.at(i).first).GetDescription() << endl;
                cout << "Quantity : " << quantities.at(i).second << endl;
            }
        }

        if(choice == 'a') {
            for (size_t i = 0; i < ListOfClients.size(); i++) {
                cout << endl << "Name : " << ListOfClients.at(i).GetName() << endl;
                for (size_t j = 0; j < ListOfOrders.size(); j++) {
                    if(i == ListOfOrders.at(j).GetId_Client()) {
                        for (size_t k = 0; k < ListOfOrders.at(j).GetId_Products().size(); k++)
                        {
                            cout << "Product : " << ListOfProducts.at(ListOfOrders.at(j).GetId_Products().at(k).first).GetDescription() << endl;
                            cout << "Quantity : " << ListOfOrders.at(j).GetId_Products().at(k).second << endl;
                        } 
                    }
                }  
            }
        }

        if(choice == '0') {
            break;
        }
    }

    save_dataclients(ListOfClients);
    save_dataproducts(ListOfProducts);
    save_dataorders(ListOfOrders);

    return 0;
}

void load_dataclients (vector<Clients> &List) {
    ifstream clients_file;
    clients_file.open("clients.txt");

    string string_from_file;
    vector<string> list_from_file;

    if (!clients_file.is_open()) {
        cout << "File clients.txt could not have been open!" << endl;
    } 
    else {
        cout << "File clients.txt opened!" << endl;
    }

    while(getline(clients_file, string_from_file)) {
        list_from_file.push_back(string_from_file);
    }

    clients_file.close();

    

    for (size_t i = 0; i < list_from_file.size(); i += 5)
    {
        size_t a = stringToSize_t(list_from_file.at(i));
        Clients b (a, list_from_file.at(i+1), list_from_file.at(i+2), list_from_file.at(i+3), list_from_file.at(i+4));
        List.push_back(b);
    }
}

void load_dataproducts (vector<Products> &List) {
    ifstream products_file;
    products_file.open("products.txt");

    string string_from_file;
    vector <string> list_from_file;

    if (!products_file.is_open()) {
        cout << "File products.txt could not have been open!" << endl;
    } 
    else {
        cout << "File products.txt opened!" << endl;
    }

    while(getline(products_file, string_from_file)) {
        list_from_file.push_back(string_from_file);
    }

    products_file.close();
    
    

    for (size_t i = 0; i < list_from_file.size(); i += 3)
    {
        size_t a = stringToSize_t(list_from_file.at(i));
        float b = stod (list_from_file.at(i+2));

        Products c (a, list_from_file.at(i+1), b);
        List.push_back(c);
    }
}

void update_clients (vector<Clients> &List1, vector<Orders> &List2) {
    char ch1;
    size_t id_client;

    while(true) {
        cout << "Enter the ID of the client you want to change : " << endl;
        cin >> id_client;

        cout << "-------------------------------------------" << endl
        << "Which data you wanna change" << endl
        << "1. Name" << endl
        << "2. CPF" << endl
        << "3. Adress" << endl
        << "4. Number" << endl
        << "5. Or erase client" << endl
        << "6. Cancel" << endl;
        cin >> ch1;

        if(ch1 == '1') {
            string new_name;

            cin.get();
            cout << "Enter the new name : " << endl;
            getline (cin, new_name);

            List1.at(id_client).SetName(new_name);

            break;
        }
        
        if(ch1 == '2') {
            string new_cpf;

            cin.get();
            cout << "Enter the new cpf : " << endl;
            getline (cin, new_cpf);

            List1.at(id_client).SetCpf(new_cpf);

            break;
        
        }

        if(ch1 == '3') {
            string new_adress;

            cin.get();
            cout << "Enter the new adress : " << endl;
            getline (cin, new_adress);

            List1.at(id_client).SetAdress(new_adress);

            break;
        }

        if(ch1 == '4') {
            string new_number;

            cin.get();
            cout << "Enter the new number : " << endl;
            getline (cin, new_number);

            List1.at(id_client).SetNumber(new_number);

            break;
        }

        if(ch1 == '5') {
            bool has_found = false;
            for (size_t i = 0; i < List2.size(); i++) {
                if(List2.at(i).GetId_Client() == id_client) {
                    has_found = true;
                    cout << i << endl;
                    break;
                } 
            }

            if(has_found == true) {
                cout << "ID is alredy being used!" << endl;
            } else {
                for (size_t i = 0; i < List1.size(); i++) {
                    if (id_client == List1.at(i).GetId_client()) {
                        List1.erase(List1.begin() + i);
                        break;
                    }
                }   
            }

            break;
        }

        if(ch1 == '6') {
            break;
        }
    }
}

void update_products(vector<Products> &List1, vector<Orders> &List2) {
    char ch2;
    size_t id_product;

    while(true) {
        cout << "-------------------------------------------" << endl
        << "Which data you wanna change" << endl
        << "1. Description" << endl
        << "2. Value" << endl
        << "3. Or erase a product" << endl
        << "4. Cancel" << endl;
        cin >> ch2;

        cout << "Enter the ID of the product you want to change : " << endl;
        cin >> id_product;

        if(ch2 == '1') {
            string new_description;

            cin.get();
            cout << "Enter the new description : " << endl;
            getline (cin, new_description);

            List1.at(id_product).SetDescription(new_description);

            break;
        }

        if(ch2 == '2') {
            float new_value;

            cout << "Enter the new value : " << endl;
            cin >> new_value;

            List1.at(id_product).SetValue(new_value);

            break;
        }
        
        if(ch2 == '3') {
            bool has_found = false;
            for (size_t i = 0; i < List2.size(); i++) {
                for (size_t j = 0; j < List2.at(i).GetId_Products().size(); j++)
                {
                    if(List2.at(i).GetId_Products().at(j).first == id_product) {
                    has_found = true;
                    break;
                    } 
                }
                
                
            }

            if(has_found == true) {
                cout << "ID is alredy being used!" << endl;
            } else {
                for (size_t i = 0; i < List1.size(); i++) {
                    if (id_product == List1.at(i).GetId_Product()) {
                        List1.erase(List1.begin() + i);
                        break;
                    }
                }   
            }

            break;
        }
        
        if(ch2 == '4') {
            break;
        }
    }

}

void load_dataorders (vector<Orders> &List1, vector<Products> &List2) {
    ifstream orders_file;
    orders_file.open("orders.txt");

    string string_from_file;
    vector<string> list_from_file;
    vector<pair<size_t, int>> itens_quant_product;

    if (!orders_file.is_open()) {
        cout << "File orders.txt could not have been open!" << endl;
    } 
    else {
        cout << "File orders.txt opened!" << endl;
    }

    while(getline(orders_file, string_from_file)) {
        list_from_file.push_back(string_from_file);
    }

    orders_file.close();

    size_t a = 0;

    for (int i = 2; i < list_from_file.size(); ) {
        for (int j = 0; j < stoi(list_from_file.at(i))*2; j += 2) {
            pair<size_t, int> new_item;
            new_item.first = stringToSize_t(list_from_file.at(i + j + 1));
            new_item.second = stoi(list_from_file.at(i + j + 2));

            itens_quant_product.push_back(new_item);
            List2.at(new_item.first).SetQuantity(List2.at(new_item.first).GetQuantity() + new_item.second);
        }
        
        Orders b (a, stringToSize_t(list_from_file.at(i-1)), itens_quant_product);
        List1.push_back(b);
        itens_quant_product.clear();

        a++;
        i += 2 * stoi(list_from_file.at(i)) + 3;
    }
}

size_t stringToSize_t(string str)
{	
	stringstream sstream(str);
	size_t result;
	sstream >> result;
	return result;
}

void save_dataclients (vector<Clients> &List) {
    ofstream clients_list;
    clients_list.open("clients.txt");

    if (clients_list.good()) {
        for (size_t i = 0; i < List.size(); i++) {
            clients_list << List.at(i).GetId_client() << "\n";
            clients_list << List.at(i).GetName() << "\n";
            clients_list << List.at(i).GetCpf() << "\n";
            clients_list << List.at(i).GetAdress() << "\n";
            clients_list << List.at(i).GetNumber() << "\n";
        }
    }

    clients_list.close();
}
void save_dataproducts (vector<Products> &List) {
    ofstream products_list;
    products_list.open("products.txt");

    if (products_list.good()) {
        for (size_t i = 0; i < List.size(); i++) {
            products_list << List.at(i).GetId_Product() << "\n";
            products_list << List.at(i).GetDescription() << "\n";
            products_list << List.at(i).GetValue() << "\n";
        }
    }

    products_list.close();
}

void save_dataorders (vector<Orders> &List) {
    ofstream orders_list;
    orders_list.open("orders.txt");

    if (orders_list.good()) {
        for (size_t i = 0; i < List.size(); i++) {
            orders_list << List.at(i).GetId_Orders() << "\n";
            orders_list << List.at(i).GetId_Client() << "\n";
            orders_list << List.at(i).GetId_Products().size() << "\n";
            for (size_t j = 0; j < List.at(i).GetId_Products().size(); j++)
            {
                orders_list << List.at(i).GetId_Products().at(j).first << "\n";
                orders_list << List.at(i).GetId_Products().at(j).second << "\n";
            }
            
        }
    }

    orders_list.close();
}
