bool isNumer(char* string) {
    bool sign = false; // if (+, -) appeared
    bool sci = false; // if (e, E) appeared
    bool decimal = false; // if . appeared
    bool head = true;
    bool num = false;
    bool require_num = false;
    while (*string != '\0') {
        if (*string == '+' || *string == '-') {

            if (head) {
                head = false;
            }
            else {
                if ((*(string-1) != 'e' && *(string-1) != 'E'))
                    return false;

                if (*(string-1) == '+' || *(string-1) == '-')
                    return false;
            }
            sign =true;
            string++;
        }
        else if (*string == 'e' || *string == 'E') {
            sci = true;
            require_num = true;
            string++;
            if (head) head=false;
        }
        else if (*string == '.') {
            if (sci || decimal) return false;
            decimal = true;
            string++;
            if (head) head=false;
        }
        else if (*string >= '0' && *string <= '9') {
            num = true;
            if (require_num) require_num=false;
            string++;
            if (head) head=false;
        }
        else return false;
    }

    if (num && !require_num) return true;
    else return false;
}