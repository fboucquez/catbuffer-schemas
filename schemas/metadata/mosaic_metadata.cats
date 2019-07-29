import "transaction.cats"

# binary layout for a mosaic metadata transaction
struct MosaicMetadataTransactionBody
	# public key of the metadata target
	targetPublicKey = Key

	# metadata key scoped to source, target and type
	scopedMetadataKey = uint64

	# unresolved mosaic id
	targetId = UnresolvedMosaicId

	# change in value size in bytes
	valueSizeDelta = int16

	# value size in bytes
	valueSize = uint16

	# value data
	value = array(byte, valueSize)

# binary layout for a non-embedded mosaic metadata transaction
struct MosaicMetadataTransaction
	const uint8 version = 1
	const EntityType entityType = 0x4244

	inline Transaction
	inline MosaicMetadataTransactionBody

# binary layout for an embedded mosaic metadata transaction
struct EmbeddedMosaicMetadataTransaction
	inline EmbeddedTransaction
	inline MosaicMetadataTransactionBody