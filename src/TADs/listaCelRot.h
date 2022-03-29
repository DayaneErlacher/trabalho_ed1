#include <stdlib.h>

#include "roteador.h"
#include "stackRot.h"

//Tipo celcelrot (tipo opaco)
typedef struct celcelrot CelCelRot;
//Tipo listacelrot (tipo opaco)
typedef struct listacelrot ListaCelRot;

/*Inicializa uma lista
 * inputs: nenhum
 * output: lista inicializada
 * pre-condicao: nenhum
 * pos-condicao: lista inicializada pronta para a inserção de celulas
 */
ListaCelRot* inicListaCelRot(void);

/*Insere celula na lista
 * inputs: lista e celula
 * output: nenhum
 * pre-condicao: lista e celula inicializados
 * pos-condicao: lista com celula inserida
 */
void insereCelRot(ListaCelRot* lista, CelRot* cel);

/*Retira a ultima celula da lista
 * inputs: lista 
 * output: lista com elemento retirado
 * pre-condicao: lista inicializada
 * pos-condicao: lista sem ultima celula
 */
CelRot* retiraCelRot(ListaCelRot* lista);

/*Libera memória alocada para a lista e para as celulas
 * inputs: lista
 * output: nenhum
 * pre-condicao: lista inicializada
 * pos-condicao: toda a memória alocada para a lista e suas celulas liberadas
 */
void liberaListaCelRot(ListaCelRot* lista);
