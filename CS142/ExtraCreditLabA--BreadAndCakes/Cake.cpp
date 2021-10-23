//
// Created by Chase Ford on 9/26/20.
//

#include "Cake.h"

Cake::Cake() {
    flavor = "NO_INIT";
    frosting = "NO_INIT";
}

Cake::Cake(string flav, string frost) {
    flavor = flav;
    frosting = frost;
}
