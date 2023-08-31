#include "FreeRTOS.h"
#include "task.h"
/*
ʹ�ù��Ӻ�����ǰ��:
    ����configUSE_IDLE_HOOKΪ1
    ʵ��vApplicationIdleHook����
*/
//define configUSE_IDLE_HOOK 1
/*
��������������ĵ����㷨:ȷ���ĸ�����̬��������л�������̬
FreeRTOSConfig.h�ļ�
    configUSE_PREEMPTION
    configUSE_TIME_SLICING
    configUSE_TICKLESS_IDLE
*/
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

int main(void)
{
    //��������(����ָ��,������,ջ��С,�������,���ȼ�,������)
    //����������xTaskCreate������ִ�е������ָ��
    xTaskCreate(&vTask1, "Task 1", 1024, NULL, 1, NULL);
    xTaskCreate(&vTask2, "Task 2", 1024, NULL, 1, NULL);
    /*�������������*/
    vTaskStartScheduler();
    
    return 0;
}
/*
������һ������,����������ܷ���,ͬһ�������������������������
�����������ڲ��໥����,����ʹ�þֲ�����,�������ռ��໥��������
ÿ���������Լ�������ջ:
    ����A�ľֲ�������������A��ջ�����B�ľֲ�������������B��ջ��
    ��ͬ����ľֲ�����,���Լ��ĸ���
*/
void vTask1(void *pvParameters)
{
    for (;;)
    {
        printf("Task 1 running\r\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    //ɾ������,����Ϊnull��ʾɾ���Լ�.ɾ��ָ��������Ҫ����������
    //vTaskDelay(NULL);
}

void vTask2(void *pvParameters)
{
    for (;;)
    {
        printf("Task 2\r\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

