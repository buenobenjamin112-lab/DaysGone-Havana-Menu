#include <kernel.h>
#include <systemservice.h>
#include <stdio.h>

extern "C" {
    int module_start(size_t args, const void *argp) {
        // Notificação exibida pelo GoldHEN ao carregar o plugin no PS4
        sceKernelSendNotificationRequest(0, "Days Gone Havana Menu Carregado com Sucesso!", -1);[span_9](start_span)[span_9](end_span)
        return 0;
    }

    int module_stop(size_t args, const void *argp) {
        sceKernelSendNotificationRequest(0, "Days Gone Havana Menu Descarregado.", -1);[span_10](start_span)[span_10](end_span)
        return 0;
    }
}
