#include <stdio.h>

#define LOG(format, ...) printf(format "\n", ##__VA_ARGS__)
#define LINEAR (1)
#define BALANCE (2)
#define SUMA (3)
#define EXIT    (4)

int main(void){
    int n, anual, eleccion = 0;
    float val, aux, deprec;

    while(eleccion != EXIT){
        LOG("Método: (%d-LR \t%d-BD \t%d-SDA \t%d-FIN)", LINEAR, BALANCE, SUMA, EXIT);
        scanf("%d", &eleccion);
        if(eleccion >= LINEAR && eleccion <= SUMA){
            LOG("Valor original del objeto:");
            scanf("%f", &val);
            LOG("Número de años:");
            scanf("%d", &n);
        }
        switch(eleccion){
            case LINEAR:{
                LOG("\n Método de la línea recta\n\n");
                deprec = val/n;
                for(anual = 1; anual<=n; ++anual){
                    val-= deprec;
                    LOG("\n --- AÑO %2d ---",anual);
                    LOG("\t Depreciación: %7.2f", deprec);
                    LOG("\t Valor actual: %8.2f",val);
                    LOG(" --- FIN AÑO %2d ---", anual);
                }
                break;
            }
            case BALANCE:{
                LOG("\n Método de balance doblemente declinante\n\n");
                for(anual = 1; anual<=n; ++anual){
                    deprec = 2*val/n;
                    val -= deprec;
                    LOG("\n --- AÑO %2d ---",anual);
                    LOG("\t Depreciación: %7.2f", deprec);
                    LOG("\t Valor actual: %8.2f",val);
                    LOG(" --- FIN AÑO %2d ---", anual);
                }
                break;
            }
            case SUMA:{
                LOG("\n Método de las suma de los digitos de los años\n\n");
                aux = val;
                for(anual = 1; anual<=n; ++anual){
                    deprec = (n-anual+1)*aux/(n*(n+1)/2);
                    val -= deprec;
                    LOG("\n --- AÑO %2d ---",anual);
                    LOG("\t Depreciación: %7.2f", deprec);
                    LOG("\t Valor actual: %8.2f",val);
                    LOG(" --- FIN AÑO %2d ---", anual);
                }
                break;
            }
            case EXIT:{
                LOG("\n Hasta pronto\n");
                break;
            }
            default:
                LOG("\nElección no valida! Intente de nuevo\n\n");
                break;
        }
    }


    return 0;
}