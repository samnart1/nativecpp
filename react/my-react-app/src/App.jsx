import { useState } from 'react'
import './App.css'
import ErrorExample from './01-useState/01-error-example'
import UseExample from './01-useState/useStateExample'
import UseObject from './01-useState/useState-object'
import EffectExample from './02-useEffect/useEffect-example'
import FetchData from './02-useEffect/fetchEffect'
import MultiReturns from './03-multipleReturns/multiReturns'
import Challenge from './03-multipleReturns/userChallenge'


function App() {
  return (
    <>
      {/* <ErrorExample/> */}
      {/* <UseExample /> */}
      {/* <UseObject /> */}
      {/* <EffectExample /> */}
      {/* <FetchData /> */}
      {/* <MultiReturns /> */}
      <Challenge />
    </>
  )
}

export default App
