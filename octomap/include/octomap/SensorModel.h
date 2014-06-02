/**
* dynamicEDT3D:
* A library for incrementally updatable Euclidean distance transforms in 3D.
* @author C. Sprunk, B. Lau, W. Burgard, University of Freiburg, Copyright (C) 2011.
* @see http://octomap.sourceforge.net/
* License: New BSD License
*/

/*
 * Copyright (c) 2011-2012, C. Sprunk, B. Lau, W. Burgard, University of Freiburg
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the University of Freiburg nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _SENSORMODEL_H_
#define _SENSORMODEL_H_

#include <bitset>

#define IDEAL_MODEL 0
#define ISM 1
#define PRISM 2
// #define SENSOR_MODEL PRISM

#define DIST_SIGMA 1
#define CORRECT_ABC 1

#define DIST_ADD 0.5

// Parameters
#define L 0.02f
#define KITTI_VELO_SIGMA 0.2f
#define KITTI_F 721.5377
#define KITTI_B 0.537150588251
#define FB KITTI_F*KITTI_B
#ifndef PI
#define PI 3.14159265359
#endif
#define F_B_SQRT_2_PI KITTI_F * KITTI_B / sqrt(2 * PI)
#define BLOCK_SIZE 0.5f
#define PRIOR 0.5f
#define ALPHA (-log(1 - PRIOR) / BLOCK_SIZE)
#define MIN_RANGE 1.5f
#define MAX_RANGE 150.0f
#define PRECALC exp(-ALPHA * BLOCK_SIZE)
#define LOG1 0
#define INTEGRATE_ACC 100
#define INTEGRATE_DX (BLOCK_SIZE / 2)

//#define PRISM_SIGMA 2.0f
//#define PRISM_MU 0

#endif
