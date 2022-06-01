#ifndef CLASSES_HPP
#define CLASSES_HPP
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class clientes {
    private:
        size_t m_id_cliente;
        string m_name;
        string m_endereco;
        string m_cpf;

    public:
        // cadastro

        clientes(size_t id, string nome, string adress, string cpf);

        void SetName(string name);
        void SetId(size_t id);
        void SetAdress(string endereco);
        void SetCpf (string cpf);

        size_t GetId();
        string GetName();
        string GetAdress();
        string GetCpf();
};

class itens {
    private:
        size_t m_id_item;
        string m_description;
        float m_value;

    public:
        itens(size_t id, string descricao, float  valor);

        void SetId_itens(size_t Id_itens);
        void Setdesc(string desc);
        void SetValor(float val);

        size_t GetId_itens();
        string GetDesc();
        float GetValor();
};

class pedidos {
    private:
        size_t  id_pedido;
        vector<size_t> id_cliente;
        vector<size_t> id_itens;

    public:
        pedidos(size_t  id, vector<size_t> id_cliente, vector<size_t> id_item);

        void SetPedido(size_t id_ped);
        void SetPedCliente(vector<size_t> id_cliente);
        void SetPedValor(vector<itens> id_itens);

        size_t GetId_Pedidos();
        clientes GetId_cliente();
        vector<size_t> GetId_itens();

        // void Square::ShowInfo()
        // {
        //     cout << " Edge: " << m_edge << " Pos: " << m_position.GetX() << " - " <<  
        //     m_position.GetY() << endl;
        // }

        
};

#endif