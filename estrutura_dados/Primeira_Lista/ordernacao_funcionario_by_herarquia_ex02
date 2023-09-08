#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define TOTAL_EMPLOYEES 21
#define EMPLOYEES_PER_HIERARCHY 7

struct Employee {
    char name[MAX_NAME_LENGTH];
};

void insertEmployee(struct Employee employees[], int hierarchy) {
    if (hierarchy < 1 || hierarchy > 3) {
        printf("Hierarquia inválida!\n");
        return;
    }

    int start = (hierarchy - 1) * EMPLOYEES_PER_HIERARCHY;
    int end = hierarchy * EMPLOYEES_PER_HIERARCHY;

    for (int i = start; i < end; i++) {
        if (strlen(employees[i].name) == 0) {
            printf("Digite o nome do funcionário: ");
            scanf("%s", employees[i].name);
            return;
        }
    }

    printf("Hierarquia está completa!\n");
}

void listEmployeesByHierarchy(struct Employee employees[], int hierarchy) {
    if (hierarchy < 1 || hierarchy > 3) {
        printf("Hierarquia inválida!\n");
        return;
    }

    printf("Funcionários da hierarquia %d:\n", hierarchy);

    int start = (hierarchy - 1) * EMPLOYEES_PER_HIERARCHY;
    int end = hierarchy * EMPLOYEES_PER_HIERARCHY;

    for (int i = start; i < end; i++) {
        if (strlen(employees[i].name) > 0) {
            printf("%s\n", employees[i].name);
        }
    }
}

void listAllEmployees(struct Employee employees[]) {
    for (int i = 0; i < TOTAL_EMPLOYEES; i++) {
        if (strlen(employees[i].name) > 0) {
            int hierarchy = (i / EMPLOYEES_PER_HIERARCHY) + 1;
            printf("Hierarquia %d - Nome: %s\n", hierarchy, employees[i].name);
        }
    }
}

int main() {
    struct Employee employees[TOTAL_EMPLOYEES];
    memset(employees, 0, sizeof(employees)); 
    int choice;
    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir funcionário\n");
        printf("2. Listar funcionários por hierarquia\n");
        printf("3. Listar todos os funcionários\n");
        printf("4. Sair\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Escolha a hierarquia (1, 2 ou 3): ");
                int hierarchy;
                scanf("%d", &hierarchy);
                insertEmployee(employees, hierarchy);
                break;
            case 2:
                printf("Escolha a hierarquia (1, 2 ou 3): ");
                int hierarchy2;
                scanf("%d", &hierarchy2);
                listEmployeesByHierarchy(employees, hierarchy2);
                break;
            case 3:
                listAllEmployees(employees);
                break;
            case 4:
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
