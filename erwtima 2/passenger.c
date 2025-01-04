#include "ipc_utils.h"
#include <unistd.h>
#include <stdio.h>

// Επιβάτης που προσπαθεί να επιβιβαστεί
static void passenger(Lifeboat *lifeboat) {
    printf("Επιβάτης περιμένει να επιβιβαστεί...\n");
    board_lifeboat(lifeboat);
    sleep(1); // Προσομοίωση χρόνου παραμονής στη λέμβο
    disembark_lifeboat(lifeboat);
    printf("Επιβάτης ολοκλήρωσε τη διαδικασία.\n");
}
