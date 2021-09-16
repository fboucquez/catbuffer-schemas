import "entity.cats"

using NodeVersion = uint32
using GenerationHashSeed = binary_fixed(32)

# node role flags
enum NodeRoleFlags : uint32
	# no roles
	NONE = 0x00

	# peer node
	PEER = 0x01

	# Api node
	API = 0x02

	# Voting node
	VOTING = 0x04

	# IPv4 compatible node
	IPV4 = 0x40

	# IPv6 compatible node
	IPV6 = 0x80

# binary layout for a network node
struct NetworkNode
	# size of the node
	size = uint32

	# version
	version = NodeVersion
	
	# unique node identifier  (public key)
	identity_key = PublicKey

	# network generation hash seed
	network_generation_hash_seed = GenerationHashSeed

	# roles
	roles = NodeRoleFlags

	# port
	port = uint16

	# network identifier
	network_identifier = NetworkType

	# size of host in bytes
	host_size = uint8

	# size of the friendly name in bytes
	friendly_name_size = uint8

	# host
	host = array(uint8, host_size)

	# friendly name
	friendly_name = array(uint8, friendly_name_size)

