#include "facet_id.h"
#include <stdlib.h>

namespace juno {

facet_metadata* internal_state::facet_metadata_arr;

void facet_metadata::initialize() {
	internal_state::facet_metadata_arr = (facet_metadata*)malloc(sizeof(facet_metadata) * FACET_CAP);
}
}
