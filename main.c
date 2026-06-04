#include "hospital.h"

int main(int argc, char* argv[]) {
    struct MedicalSystemState system;
    int choice;
    char input_file[INPUT_SIZE];
    char output_file[INPUT_SIZE];
    system_state_init(&system);
    choose_input_file(input_file, sizeof(input_file), argc > 0 ? argv[0] : "");
    choose_output_file(output_file, sizeof(output_file), input_file);
    load_data_from_file(&system, input_file);
    save_all_data_files(&system, input_file, output_file);
    while (1) {
        show_menu();
        choice = read_int("Chon chuc nang: ");
        if (choice == 0) {
            break;
        } else if (choice == 1) {
            menu_add_department(&system);
        } else if (choice == 2) {
            menu_add_doctor(&system);
        } else if (choice == 3) {
            menu_add_patient(&system);
        } else if (choice == 4) {
            menu_register_exam(&system);
        } else if (choice == 5) {
            menu_call_next(&system);
        } else if (choice == 6) {
            menu_show_queue(&system);
        } else if (choice == 7) {
            menu_list_patients(&system);
        } else if (choice == 8) {
            menu_list_doctors(&system);
        } else if (choice == 9) {
            menu_list_departments(&system);
        } else if (choice == 10) {
            menu_daily_statistics(&system);
        } else {
            printf("Lua chon khong hop le.\n");
        }
        if (choice != 0) {
            save_all_data_files(&system, input_file, output_file);
            press_enter();
        }
    }
    save_all_data_files(&system, input_file, output_file);
    system_state_free(&system);
    printf("Da thoat chuong trinh.\n");
    return 0;
}
