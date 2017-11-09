# Latency Lab

<p align="left">
<a href="https://travis-ci.org/Open-Markets-Initiative/latency-lab"><img src="https://img.shields.io/travis/Open-Markets-Initiative/latency-lab.svg?style=flat-square"/></a>
</p>

Composable tools for automated network application latency measurement and 
reporting.

External application throughput can be measured scientifically by matching
outbound response events to inbound trigger events.  Provided a standard 
packet capture, this latency lab provides components to quickly create 
custom tools for accurate benchmarking, verification and system analysis.

## Examples

### [Latency Report](https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/report/output/report.html)

The example data represents a series of outbound CME fix orders triggered
by CME SBE market data packets. The spike at the beginning is due to core 
warming.

### [Comparison Report](https://rawgit.com/Open-Markets-Initiative/latency-lab/master/example/comparison/output/comparison.html)

A comparison report allows for quickly comparing application response to 
multiple different data speeds.

See [examples](https://github.com/Open-Markets-Initiative/latency-lab/tree/master/example "List of Example Latency Measurements") directory for more use cases and build instructions.

## Disclaimer

The Open Markets Initiative (Omi) is a group of technologists dedicated to 
enhancing the stability of electronic financial markets using modern 
development methods.

All example input data are faked records modeled on tshark dissections. 
Any similaraity between existing people, places and/or protocols is purely 
incidental. 

Enjoy.
