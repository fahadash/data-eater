<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="text" />
<xsl:param name="param1" select="success" />
<xsl:template match="/"><xsl:value-of select="$param1" /></xsl:template>
</xsl:stylesheet>
