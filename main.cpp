#include <iostream>
#include <vector>

using namespace std;

bool primo(int num)
{
    bool prim = true;
    for(int i = 2; i < num; i++)
    {
        if(num%i==0)
        {
            prim = false;
        }
    }
    return prim;
}

vector<int> algor(int num)
{
    vector<int> aux;
    int contador = 0;
    for(int i = 2; i <= num;) {
        if (primo(i)) {
            if (num % i == 0) {
                contador++;
                num /= i;
                if (num == 1)aux.push_back(contador);
            } else {
                aux.push_back(contador);
                contador = 0;
                i++;
            }
        }
        else{i++;}
    }
    return aux;
}

vector<vector<int>> iteraciones(int num)
{
    vector<vector<int>> aux;
    for(int i = 2; i <= num; i++)
    {
        aux.push_back(algor(i));
    }
    return aux;
}

int hallar_max(vector<vector<int>> aa)
{
    int mx=0;
    for(int i = 0; i < aa.size();i++)
    {
        if((aa[i].size())>mx)
        {
            mx = aa[i].size();
        }
    }
    return mx;
}

vector<vector<int>> rellenar_ceros(vector<vector<int>> rpta)
{
    for(int j = 0; j < rpta.size();j++) {
        for (int i = rpta[j].size(); i < hallar_max(rpta); i++) {
            rpta[j].push_back(0);
        }
    }
    return rpta;
}

vector<int> suma(vector<vector<int>> rpta)
{
    rpta = rellenar_ceros(rpta);
    vector<int> sumas;
    for(int i = 0; i < hallar_max(rpta);i++ )
    {
        int sum = 0;
        for(int j = 0; j<rpta.size();j++)
        {
            sum = sum  + rpta[j][i];
        }
        sumas.push_back(sum);
    }
    return sumas;
}



void imprimir_rpta(vector<int> suma)
{
    for(int i = 0; i < suma.size(); i++)
    {
        cout<<suma[i]<<" ";
    }
}

int main() {
    int inp=13;
    vector <int> numeros;
    vector <vector<int>> rptas;
    vector <int> inputs;
    while(inp!=0)
    {
        cin>>inp;
        if(inp != 0)
            inputs.push_back(inp);
    }
    for(auto i: inputs)
    {
        rptas = iteraciones(i);
        numeros = suma(rptas);
        cout<<i<<"!"<<" = ";
        imprimir_rpta(numeros);
        cout<<endl;
    }
}