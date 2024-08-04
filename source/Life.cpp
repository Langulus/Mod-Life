///                                                                           
/// Langulus::Module::Life                                                    
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include "Life.hpp"

LANGULUS_DEFINE_MODULE(
   Life, 0, "Life",
   "Life simulation module - "
   "allows for creation of ecosystems and organisms", "",
   Life, Ecosystem, Organism
)


/// Module construction                                                       
///   @param runtime - the runtime that owns the module                       
///   @param descriptor - instructions for configuring the module             
Life::Life(Runtime* runtime, const Neat&)
   : Resolvable {this}
   , A::Module  {runtime}
   , mEcosystems{this} {
   VERBOSE_LIFE("Initializing...");
   VERBOSE_LIFE("Initialized");
}

///                                                                           
Life::~Life() {

}

/// Module update routine                                                     
///   @param deltaTime - time between updates                                 
///   @return false if the UI requested exit                                  
bool Life::Update(Time deltaTime) {
   return true;
}

/// Create/Destroy ecosystems                                                 
///   @param verb - the creation/destruction verb                             
void Life::Create(Verb& verb) {
   mEcosystems.Create(verb);
}