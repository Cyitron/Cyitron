#include "classes.hpp"

clientes::clientes(size_t id, string nome, string adress, string cpf) {
    m_id_cliente = id;
    m_name = nome;
    m_endereco = adress;
    m_cpf = cpf;
}

void clientes::SetId(size_t id) {
    m_id_cliente = id;
}
void clientes::SetName(string name) {
    m_name = name;
}
void clientes::SetAdress(string endereco) {
    m_endereco = endereco;
}
void clientes::SetCpf (string cpf) {
    m_cpf = cpf;
}

size_t clientes::GetId() {
    return m_id_cliente;
}
string clientes::GetName() {
    return m_name;
}
string clientes::GetAdress() {
    return m_endereco;
}
string clientes::GetCpf() {
    return m_cpf;
}

itens::itens(size_t id, string descricao, float  valor) {
    m_id_item = id;
    m_description = descricao;
    m_value = valor;
}

void itens::SetId_itens(size_t Id_itens) {
    m_id_item = Id_itens;
}
void itens::Setdesc(string desc) {
    m_description = desc;
}
void itens::SetValor(float val) {
    m_value = val;
}

size_t itens::GetId_itens() {
    return m_id_item;
}
string itens::GetDesc() {
    return m_description;
}
float itens::GetValor() {
    return m_value;
}
