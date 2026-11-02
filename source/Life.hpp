///                                                                           
/// Langulus::Module::Life                                                    
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Ecosystem.hpp"
#include <Langulus/Verbs/Create.hpp>


///                                                                           
///   Life module                                                             
///                                                                           
/// Manages and produces ecosystems                                           
struct Life final : Things::Life {
   using CTTI_Abstract  = No;
   using CTTI_Bases     = Things::Life;
   using CTTI_Ability   = Verbs::Create;

private:
   // List of created input gatherers                                   
   TFactory<Ecosystem> mEcosystems;

public:
   Life(Runtime*, Neat const&);

   bool Update(Time);
   void Create(Verb&);
   void Teardown();
};