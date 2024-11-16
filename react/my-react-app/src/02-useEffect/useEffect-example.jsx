import { useState, useEffect } from 'react'

const EffectExample = () => {
  const [value, setValue] = useState(0)

  const clickHandler = () => {
    setValue(value + 1)
  }

  useEffect(() => {
    console.log('This is from use Effect')
  }, [])

  console.log('This is from outside useEffect')

  return (
    <>
      <div>
        <h2>{value}</h2>
        <button type="button" onClick={clickHandler}>
          Click Me
        </button>
      </div>
    </>
  )
}

export default EffectExample
