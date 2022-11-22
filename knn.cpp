#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <set>

using namespace std;
class Individuo{

private:
    string classe;
    double a, b, c, d;
public:
    Individuo(double a, double b, double c, double d, string classe){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->classe = classe;
    }
    string getClasse(){
        return classe;
    }
    double getA(){
        return a;
    }
    double getB(){
        return b;
    }
    double getC(){
        return c;
    }
    double getD(){
        return d;
    }
};

double distancia_euclidiana(Individuo ind_01, Individuo ind_02){
    double soma = pow((ind_01.getA() - ind_02.getA()), 2) + pow((ind_01.getB() - ind_02.getB()), 2) +
            pow((ind_01.getC() - ind_02.getC()), 2) + pow((ind_01.getD() - ind_02.getD()), 2);
    return sqrt(soma);
}

string classificado_amostra(vector<individuo>& individuos, Individuo novo_exemplo, int k){
    // Se k == par -> decrementa
    if (k % 2 == 0){
        k--;
        if(k <= 0){
            k = 1;
        }
    }
    int tamanho_vetor = individuos.size();
    set<pair<double, int>> dist_individuos;
    for(int i = 0; i < tamanho_vetor; i++){
        double dist = distancia_euclidiana(individuos[i], novo_exemplo);
        dist_individuos.insert(make_pair(dist, i));
    }

    set<pair<double, int>>::iterator it;
    vector<int> cont_class(3);
    int cont_k = 0;

    for(it = dist_individuos.begin(); it != dist_individuos.end(); it++){
        string classe  = individuos[it->second].getClasse();

        if (classe == "Iris-setosa"){
            cont_classes[0]++
        }
        else if (classe == "Iris-versicolor"){
            cont_classes[1]++;
        }
        else{
            cont_classes[2]++;
        }
        if(cont_k > k) break;
            cont_k++;
    }
    
    string classe_classificacao;
    if(cont_classes[0] >= cont_classes[1] && cont_classes[0] >= cont_classes[2]){
        classe_classificacao = "Iris-setosa";
    }
    else if(cont_classes[1] >= cont_classes[0] && cont_classes[1] >= cont_classes[2]){
        classe_classificacao = "Iris-versicolor"
    }
    else{
        classe_classificacao = "Iris-virginica"
    }
    return classe_classificacao;

}

int main(int argc, int *argv[]){

}
