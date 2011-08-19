#ifndef OCTOMAP_OCTREE_NODE_H
#define OCTOMAP_OCTREE_NODE_H

// $Id$

/**
* OctoMap:
* A probabilistic, flexible, and compact 3D mapping library for robotic systems.
* @author K. M. Wurm, A. Hornung, University of Freiburg, Copyright (C) 2009-2011
* @see http://octomap.sourceforge.net/
* License: New BSD License
*/

/*
 * Copyright (c) 2009-2011, K. M. Wurm, A. Hornung, University of Freiburg
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

#include "octomap_types.h"
#include "octomap_utils.h"
#include "OcTreeDataNode.h"
#include <limits>

namespace octomap {

  /**
   * Nodes to be used in OcTree. They represent 3d occupancy grid cells.
   *
   * Hint: If a class is derived from OcTreeNode, you have to implement (at least) 
   * createChild, getChild, and getChild const. See OcTreeNodeLabeled for an example.
   *
   */
  class OcTreeNode : public OcTreeDataNode<float> {

  public:
    OcTreeNode();
    ~OcTreeNode();

    bool createChild(unsigned int i);

    // overloaded, so that the return type is correct:
    inline OcTreeNode* getChild(unsigned int i) {
      return static_cast<OcTreeNode*> (OcTreeDataNode<float>::getChild(i));
    }
    inline const OcTreeNode* getChild(unsigned int i) const {
      return static_cast<const OcTreeNode*> (OcTreeDataNode<float>::getChild(i));
    }

    // -- node occupancy  ----------------------------

    /// \return occupancy probability of node
    inline double getOccupancy() const { return probability(value); }

    /// \return log odds representation of occupancy probability of node
    inline float getLogOdds() const{ return value; }
    /// sets log odds occupancy of node
    inline void setLogOdds(float l) { value = l; }

    /**
     * @return mean of all children's occupancy probabilities, in log odds
     */
    double getMeanChildLogOdds() const;

    /**
     * @return maximum of children's occupancy probabilities, in log odds
     */
    float getMaxChildLogOdds() const;

    /// update this node's occupancy according to its children's maximum occupancy
    inline void updateOccupancyChildren() {
      this->setLogOdds(this->getMaxChildLogOdds());  // conservative
    }

    /// adds p to the node's logOdds value (with no boundary / threshold checking!)
    void addValue(const float& p);


    // deprecated methods ################################################

    /// This function is deprecated and will be removed,
    /// instead use octree->isNodeOccupied(node) in OccupancyOcTreeBase
    ///
    /// \return true if occupancy probability of node is >= OCC_PROB_THRES
    /// For efficiency, values are compared in log-space (no need for exp-computation)
    DEPRECATED( inline bool isOccupied() ) {
      return (this->getLogOdds() >= occProbThresLog);
    }

    /// This function is deprecated and will be removed,
    /// instead use octree->isNodeAtThreshold(node) in OccupancyOcTreeBase
    ///
    /// node has reached the given occupancy threshold (CLAMPING_THRES_MIN, CLAMPING_THRES_MAX)
    DEPRECATED( inline bool atThreshold() const ) {
      return ((value <= clampingThresMin) ||
              (value >= clampingThresMax));
    }

    /// This function is deprecated and will be removed,
    /// instead use octree->nodeToMaxLikelihood(node) in OccupancyOcTreeBase
    ///
    /// rounds a node's occupancy value to the nearest clamping threshold (free or occupied),
    /// effectively setting occupancy to the maximum likelihood value
    DEPRECATED( void toMaxLikelihood() );

    /// This function is deprecated and will be removed,
    /// instead use octree->integrateHit(node) in OccupancyOcTreeBase
    ///
    /// integrate a measurement (beam ENDED in cell)
    DEPRECATED( inline void integrateHit() ) {  updateProbability(probHit); }

    /// This function is deprecated and will be removed,
    /// instead use octree->integrateMiss(node) in OccupancyOcTreeBase
    ///
    /// integrate a measurement (beam PASSED in cell)
    DEPRECATED( inline void integrateMiss() ) { updateProbability(probMiss); }
    

  protected:
    /// update the probability of a node, p will first be converted to logodds
    /// this will eventually be removed (see deprecations above)
    void updateProbability(double p);

    // definition of "Occupancy"
    // These values are deprecated and should no longer be used.
    // Use the parameters of the tree instead (and e.g. tree->isNodeOccupied(node))
    const static double probHit; // = 0.7;
    const static double probMiss; //= 0.4;
    const static float occProbThres; //= 0.5;
    const static float occProbThresLog; // = 0.0;
    const static float clampingThresMin; // = -2;
    const static float clampingThresMax; // = 3.5;

    // "value" stores log odds occupancy probability
  };

} // end namespace

#endif