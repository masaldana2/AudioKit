#include "plumber.h"

int sporth_thresh(sporth_stack *stack, void *ud)
{
    plumber_data *pd = ud;
    SPFLOAT input;
    SPFLOAT trig;
    SPFLOAT threshold;
    int mode;
    sp_thresh *thresh;

    switch(pd->mode) {
        case PLUMBER_CREATE:

#ifdef DEBUG_MODE
            fprintf(stderr, "thresh: Creating\n");
#endif

            sp_thresh_create(&thresh);
            plumber_add_ugen(pd, SPORTH_THRESH, thresh);
            if(sporth_check_args(stack, "fff") != SPORTH_OK) {
                fprintf(stderr,"Not enough arguments for thresh\n");
                stack->error++;
                return PLUMBER_NOTOK;
            }
            sporth_stack_push_float(stack, 0);
            break;
        case PLUMBER_INIT:

#ifdef DEBUG_MODE
            fprintf(stderr, "thresh: Initialising\n");
#endif

            mode = (int)sporth_stack_pop_float(stack);
            threshold = sporth_stack_pop_float(stack);
            input = sporth_stack_pop_float(stack);
            thresh = pd->last->ud;
            sp_thresh_init(pd->sp, thresh);
            sporth_stack_push_float(stack, 0);
            break;
        case PLUMBER_COMPUTE:
            mode = (int)sporth_stack_pop_float(stack);
            threshold = sporth_stack_pop_float(stack);
            input = sporth_stack_pop_float(stack);
            thresh = pd->last->ud;
            thresh->thresh = threshold;
            thresh->mode = mode;
            sp_thresh_compute(pd->sp, thresh, &input, &trig);
            sporth_stack_push_float(stack, trig);
            break;
        case PLUMBER_DESTROY:
            thresh = pd->last->ud;
            sp_thresh_destroy(&thresh);
            break;
        default:
            fprintf(stderr, "thresh: Uknown mode!\n");
            break;
    }
    return PLUMBER_OK;
}
