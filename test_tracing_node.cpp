/*
 * This file is part of SPORE.
 *
 * Copyright (c) 2016, Institute for Theoretical Computer Science,
 * Graz University of Technology
 *
 * SPORE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * SPORE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SPORE.  If not, see <http://www.gnu.org/licenses/>.
 *
 * For more information see: https://github.com/IGITUGraz/spore-nest-module
 *
 * File:   test_tracing_node.cpp
 */

#include "test_tracing_node.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "tracing_node.h"

namespace spore
{

/**
 * Constructor.
 */
TestTracingNode::TestTracingNode()
:SporeTestBase("test_tracing_node")
{}

/**
 * Execute once at startup.
 */
void TestTracingNode::check(nest::delay time_step, TracingNode *node)
{
    test_assert(node->get_num_traces()==5, "number of traces");
    
    for (int tid=0; tid<node->get_num_traces(); tid++)
    {
        for (size_t t=0; t<time_step; t++)
        {
            //std::cout << (*node->get_trace(t, tid)) << " <-> " << t+tid << std::endl;
            test_assert( (*node->get_trace(t, tid))==t+tid, "trace content");
        }
    }
}

}

