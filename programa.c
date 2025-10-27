#include <stdio.h>

int main()
{
    int estudiantes = 5, asignaturas = 3;
    float nota_apro = 6;
    
    float cal[5][3];
    
    float prom_est[estudiantes];
    float max_est[estudiantes];
    float min_est[estudiantes];
    
    float prom_asig[asignaturas];
    float max_asig[asignaturas];
    float min_asig[asignaturas];
    
    int aprobados_asig[asignaturas];
    int reprobados_asig[asignaturas];
    
    float nota;
    
    printf("-----Ingreso de las CALIFICACIONES (0-10)xd-----\n");
    
    for(int i = 0; i < estudiantes; i++)
    {
        printf("\n-----Estudiante %d-----\n", i+1);
        
        for(int j = 0; j < asignaturas; j++)
        {
           do{
               printf("\nIngrese calificacion para la asignatura %d: ", j+1);
               scanf("%f", &nota);
               
               if (nota < 0 || nota > 10) {
                    printf("Error #217(se ve chido): La calificacion debe estar entre 0 y 10. Intente de nuevo.\n");
                }
           } while(nota < 0 || nota > 10);
           
           cal[i][j] = nota;
        }
    }
    
    for(int i = 0; i < estudiantes; i++)
    {
        float suma_est = 0;
        float min_notaE = 10.0;
        float max_notaE = 0.0;
        
        for(int j = 0; j < asignaturas; j++)
        {
            float nota = cal[i][j];
            suma_est += nota;
            
            if(nota< min_notaE)
            {
                min_notaE = nota;
            }
            if(nota> max_notaE)
            {
                max_notaE = nota;
            }
        }
        
        prom_est[i] = suma_est / asignaturas;
        min_est[i] = min_notaE;
        max_est[i] = max_notaE;
    }
    
    for(int j = 0; j < asignaturas; j++)
    {
        float suma_asig = 0;
        float min_notaA = 10.0;
        float max_notaA = 0.0;
        
        int aprobados = 0;
        
        for(int i = 0; i < estudiantes; i++)
        {
            float nota = cal[i][j];
            suma_asig += nota;
            
            if(nota< min_notaA)
            {
                min_notaA = nota;
            }
            if(nota> max_notaA)
            {
                max_notaA = nota;
            }
        }
        
        prom_asig[j] = suma_asig / estudiantes;
        min_asig[j] = min_notaA;
        max_asig[j] = max_notaA;
        
        aprobados_asig[j] = aprobados;
        reprobados_asig[j] = estudiantes - aprobados;
    }
    
    printf("\n=============================================");
    printf("\n===CALIFICACIONES===");
    printf("\n=============================================");
    
    printf("\n1. Resultados por estudiante\n");
    
    for(int i = 0; i< estudiantes; i++)
    {
        printf("Estudiante %d: \n", i+1);
        printf("Promedio: %.2f \n", prom_est[i]);
        printf("Calificacion mas alta: %.2f \n", max_est[i]);
        printf("Calificacion mas baja: %.2f \n", min_est[i]);
        
        printf("\n");
    }
    
    printf("\n=============================================");
    printf("\n2. Resultados por asignatura\n");
    
    for(int j = 0; j< asignaturas; j++)
    {
        printf("Asignatura %d: \n", j+1);
        printf("Promedio: %.2f \n", prom_asig[j]);
        printf("Calificacion mas alta: %.2f \n", max_asig[j]);
        printf("Calificacion mas baja: %.2f \n", min_asig[j]);
        
        printf("Estudiantes aprobados: %.2f \n", aprobados_asig[j]);
        printf("Estudiantes reprobados: %.2f \n", reprobados_asig[j]);
        
        printf("\n");
    }

    return 0;
}
