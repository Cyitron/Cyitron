#ifndef CLASSES_HPP
#define CLASSES_HPP
#include <iostream>
#include <vector>

using namespace std;

class clientes {
    private:
        size_t id_cliente;
        string name;
        string endereco;
        string _cpf;

    public:
        // cadastro
        clientes(size_t id, string nome, string adress, string cpf);
        void SetName(string name);
        void SetId(size_t Id);
        void SetAdress(string endereco);
        void SetCpf (string cpf);

        size_t GetName();
        string GetId();
        string GetAdress();
        string GetCpf();
};

class itens {
    private:
        size_t id_item;
        string description;
        float value;

    public:
        itens(size_t id, string descricao, float valor);
        void SetId_itens(size_t Id_itens);
        void Setdesc(string desc);
        void SetValue(float value);

        size_t GetId_itens();
        string GetDesc();
        float GetValue();
};

class pedidos {
    private:
        size_t  id_pedido;
        clientes id_cliente;
        vector<size_t> id_itens;

    public:
        pedidos(size_t id, clientes cliente, vector<size_t> item);

        void SetPedido(size_t id_ped);
        void SetPedCliente(clientes cliente);
        void SetPedValor(vector<size_t> id_itens);

        size_t GetId_Pedidos();
        clientes GetId_cliente();
        vector<size_t> GetId_itens();

        void Clientes::ShowInfo()
        {
            cout << " ID: " <<  << " Nome: " << m_position.GetX() << " Endereço: " <<  
            m_position.GetY() << "CPF: " << cpf << endl;
        }

        
};

#endif