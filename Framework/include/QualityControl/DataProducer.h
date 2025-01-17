// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

///
/// \file   DataProducer.h
/// \author Piotr Konopka
///

#ifndef QUALITYCONTROL_DATAPRODUCER_H
#define QUALITYCONTROL_DATAPRODUCER_H

#include <string>
#include <Framework/DataProcessorSpec.h>

namespace o2::quality_control::core
{

/// \brief Returns a random data producer specification which publishes on {"TST", "RAWDATA", <index>}
///
/// \param minSize  Minimum size of a message in bytes
/// \param maxSize  Maximum size of a message in bytes
/// \param rate     How much messages to produce in one second
/// \param amount   How many messages should be produce in total (0 for inf). EndOfStream is sent at the end.
/// \param index    SubSpecification of the data producer (useful when more than one needed)
/// \param monitoringUrl Where monitoring metrics should be sent
/// \param fill     Should it fill messages with random data
///
/// \return         A random data producer specification
framework::DataProcessorSpec
  getDataProducerSpec(size_t minSize, size_t maxSize, double rate, uint64_t amount = 0, size_t index = 0,
                      std::string monitoringUrl = "", bool fill = true, size_t timepipeline = 1);

/// \brief Returns an algorithm generating random messages
///
/// \param output   Origin, Description and SubSpecification of data to be produced
/// \param minSize  Minimum size of a message in bytes
/// \param maxSize  Maximum size of a message in bytes
/// \param rate     How much messages to produce in one second
/// \param amount   How many messages should be produce in total (0 for inf). EndOfStream is sent at the end.
/// \param monitoringUrl Where monitoring metrics should be sent
/// \param fill     Should it fill messages with random data
///
/// \return         A random data producer algorithm
framework::AlgorithmSpec
  getDataProducerAlgorithm(framework::ConcreteDataMatcher output, size_t minSize, size_t maxSize, double rate,
                           uint64_t amount = 0, std::string monitoringUrl = "", bool fill = true);

} // namespace o2::quality_control::core

#endif //QUALITYCONTROL_DATAPRODUCER_H
