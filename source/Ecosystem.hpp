///                                                                           
/// Langulus::Module::Life                                                    
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Organism.hpp"
#include <Langulus/Factory.hpp>


///                                                                           
///   Ecosystem                                                               
///                                                                           
/// A place where organisms interact with each other and the world.           
///                                                                           
struct Ecosystem final : Things::Ecosystem, ProducedFrom<Life> {
   using CTTI_Abstract = No;
   using CTTI_Producer = Life;
   LANGULUS_BASES(Things::Ecosystem);
   LANGULUS_VERBS(Verbs::Create);

private:
   // List of participating organisms                                   
   TFactory<Organism> mOrganisms;

public:
   Ecosystem(Life*, Many const&);

   bool Update(Time);
   void Create(Verb&);
   void Refresh();
   void Teardown();
};