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
Life::Life(Runtime* runtime, const Many&)
   : Resolvable {this}
   , A::Module  {runtime} {
   VERBOSE_LIFE("Initializing...");
   VERBOSE_LIFE("Initialized");
}

/// Module update routine                                                     
///   @param deltaTime - time between updates                                 
///   @return false                                                           
bool Life::Update(Time deltaTime) {
   for (auto& ecosystem : mEcosystems)
      ecosystem.Update(deltaTime);
   return false;
}

/// Create/Destroy ecosystems                                                 
///   @param verb - the creation/destruction verb                             
void Life::Create(Verb& verb) {
   mEcosystems.Create(this, verb);
}