#include "facet_id.h"
#include <stdlib.h>

facet_metadata* facet_metadata_arr;

void facet_metadata::initialize() {
	facet_metadata_arr = (facet_metadata*)malloc(sizeof(facet_metadata) * FACET_CAP);
}
